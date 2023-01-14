#include "riverGameMode.h"
#include "tdGameplay.h"
#include "dcMath.h"
#include "TestTile.h"
#include "assets/td_VAPOR_hull.h"
#include "LVL_Loncha_00.h"
#include "LVL_Loncha_01.h"
#include "LVL_Loncha_02.h"
#include "LVL_Loncha_03.h"
#include "tdConfig.h"
#include <libetc.h>
#include <stdio.h>

#define IMMUNITY_BLINK_RATE 3
#define HIT_IMMUNITY_DURATION 60
#define WALL HIT_IMMUNITY_DURATION 30

#define MAX_OBSTACLES_PER_LONCHA 50

extern SDC_Broadphase Broadphase;

SDC_Camera* RiverGameModeCamera;
SDC_Render* RiverGameModeRender;


extern tdLoncha levelData_LVL_Lonchas;
extern unsigned long _binary_assets_textures_texturaEpica_tim_start[];

extern tdTIMDataHandler timData[];
SDC_Camera riverCamera;

SDC_Texture riverBackground;
int riverBackgroundInitialized = 0;
extern unsigned long _binary_assets_textures_sky_psx_tim_start[];

unsigned CurrentObstacles[MAX_OBSTACLES_PER_LONCHA];
unsigned numObstacles;   

tdGameMode riverGameMode = 
{
    .camera = &riverCamera,
    .initFunction = &riverInitScene,
    .updateLoopFunction = &riverUpdateScene,
    .drawFunction = &riverDrawScene
};

enum ESteeringDirection 
{
    STEERING_RIGHT,
    STEERING_LEFT,
    STEERING_NONE
};
tdLoncha* currentLoncha;
tdLoncha* nextLoncha;

tdLoncha* currentPhisicsLoncha;
unsigned long CurrentFrame = 0;

VECTOR lonchaOffset = {0};

int offsetToChangeLoncha = 8900;

tdActor Player;
int bPlayerVisible = 1;
long CurrentSteering = 0;
int bImmune = 0;
int CurrImmunityFrames = 0;
int ImmunityDuration = 0;

// Movement Variables
int scrollSpeed = 65;
int maxScrollSpeed = 300;
int scrollSpeedIncreasePerLoncha = 60;
long SteeringStep = 100;
long FrictionStep = 70;

short MaxRotationAngle = 30;
long MaxSteering = 300;
long MinSteering = 40;
int PrevSteering = STEERING_NONE;

int currentCinematicTime = 0;
int totalCinematicDuration = 2048;
SVECTOR introCinematicPath[] = {
    {0, 310, 1160},
    {-740, 370, 340+1000},
    {-740, 370, -840+1000},
    {550, 370, -840+1000},
    {550, 370, 510},
    {0, 1000, 2000}
};
SVECTOR introCinematicLookAt[] = {
    {0, 0, 1000},
    {0, 0, 1000},
    {0, 0, 1000},
    {0, 0, 1000},
    {0, 0, 0},
    {0, 0, 0}
};
char bCinematicMode = 0;

extern int bEpicDebugMode;
extern unsigned long _binary_assets_textures_texturaEpica_tim_start[];

tdLoncha* lonchasList[] = {
    &levelData_LVL_Loncha_00,
    &levelData_LVL_Loncha_01,
    &levelData_LVL_Loncha_02,
    &levelData_LVL_Loncha_03
};

int idInLonchasList = 0;

int cameraLagTime = 100;
SVECTOR targetCameraPosOffset = {0};
SVECTOR cameraPosOffset = {0};
SVECTOR targetCameraLookAtOffset = {0};
SVECTOR cameraLookAtOffset = {0};

void DrawBackground(tdGameMode* gameMode, SDC_Render* render);

// Loads texture data an computes meshes bounding boxes
void InitializeLonchas()
{
    int numLonchasInList = sizeof(lonchasList) / sizeof(lonchasList[0]);
    for(int i = 0; i<numLonchasInList; ++i)
    {
        tdLoncha* loncha = lonchasList[i];
        for(int j = 0; j<loncha->numActors; ++j)
        {
            // Initialize texture data
            SDC_Texture* textureData = GetTextureDataAndLoadIfNeeded( loncha->actors[i].meshData.texture_tim);
            loncha->actors[i].meshData.mesh->textureData = *textureData;
            
            // Initialize bounding box
            InitializeActorBoundingBoxBasedOnMesh(&loncha->actors[i]);
        }
    }
}

void ClearObstacles()
{
    for(int i = 0; i < numObstacles; ++i)
    {
        dcBF_removeShape(&Broadphase,CurrentObstacles[i]);
    }
    numObstacles = 0;
}

void registerLonchaObstacles(tdLoncha* Loncha)
{
    numObstacles = 0;
    for(int i = 0; i < Loncha->numCollisions; ++i)
    {
        if (i > MAX_OBSTACLES_PER_LONCHA)
        {
            printf("Too many obstacles in a loncha :(");
            return;
        }
        SDC_Shape shape;
        shape.shapeType = ST_OOBB;
        shape.oobb.center = Loncha->collisions[i].center;
        shape.oobb.center.vz -= offsetToChangeLoncha >> 1;
        shape.oobb.halfSize.vx = abs(Loncha->collisions[i].halfSize.vx);
        shape.oobb.halfSize.vy = abs(Loncha->collisions[i].halfSize.vy);
        shape.oobb.halfSize.vz = abs(Loncha->collisions[i].halfSize.vz);
        shape.oobb.rotation = Loncha->collisions[i].rotation;

        CurrentObstacles[numObstacles] = dcBF_addShape(&Broadphase, &shape);
        numObstacles++;   
    }
}

void IncrementScrollSpeed()
{
    scrollSpeed += scrollSpeedIncreasePerLoncha;
    if(scrollSpeed > maxScrollSpeed)
    {
        scrollSpeed = maxScrollSpeed;
    }
}
void IncrementLonchasListId()
{
    idInLonchasList++;
    int numLonchasInList = sizeof(lonchasList) / sizeof(lonchasList[0]);
    if(idInLonchasList >= numLonchasInList)
    {
        idInLonchasList = 0;
    }
}

tdLoncha* GetNewLoncha(void)
{
    tdLoncha* newLoncha = lonchasList[idInLonchasList];
    IncrementLonchasListId();
    
    return newLoncha;
}

void OnPlayerObstacleHit()
{
    if (bImmune)
        return;

    CurrImmunityFrames = 0;
    ImmunityDuration = HIT_IMMUNITY_DURATION;
    bImmune = 1;
}

void riverInitScene(tdGameMode* gameMode)
{
    if (!riverBackgroundInitialized)
    {
        TIM_IMAGE timImage;
        dcRender_LoadTexture(&timImage, _binary_assets_textures_sky_psx_tim_start);
        riverBackground.mode = timImage.mode;
        riverBackground.crect = *timImage.crect;
        riverBackground.prect = *timImage.prect;
        riverBackgroundInitialized = 1;
    }
    
    InitializeLonchas();

    dcCamera_SetScreenResolution(gameMode->camera, SCREEN_WIDTH, SCREEN_HEIGHT);
    lonchaOffset = VECTOR_ZERO;
    currentLoncha = GetNewLoncha();
    nextLoncha = GetNewLoncha();

    Player.meshData.mesh = &td_VAPOR_hull_Mesh;
    Player.meshData.texture_tim = _binary_assets_textures_texturaEpica_tim_start;
    SDC_Texture* textureData = GetTextureDataAndLoadIfNeeded(Player.meshData.texture_tim);
    Player.meshData.mesh->textureData = *textureData;
    Player.scale.vx = 4000;
    Player.scale.vy = 4000;
    Player.scale.vz = 4000;

    Player.position = VECTOR_ZERO;
    Player.rotation = SVECTOR_ZERO;

    Player.rotation.vy = 2000;

    Player.position.vz = 1000;

    if(bIntroCinematicEnabled)
    {
        bCinematicMode = 1;
        currentCinematicTime = 0;
    }
    
}

void updatePlayerImmunity()
{
    if (!bImmune)
        return;

    if (CurrImmunityFrames % IMMUNITY_BLINK_RATE == 0)
    {
        bPlayerVisible = bPlayerVisible ? 0 : 1;
    }

    CurrImmunityFrames++;
    if (CurrImmunityFrames > ImmunityDuration)
    {
        bImmune = 0;
        bPlayerVisible = 1;
    }
}

void updateCollisions()
{
    SDC_Shape sphereShape;
    sphereShape.shapeType = ST_SPHERE;
    sphereShape.sphere.center = Player.position; 
    sphereShape.sphere.radius = 110;

    if( dcBF_shapeCollides(&Broadphase, &sphereShape ,RiverGameModeRender, RiverGameModeCamera ) )
    {
        OnPlayerObstacleHit();
    }
}

void updatePlayer()
{
    int bSteeringInThisFrame = 0;
    
    u_long padState = PadRead(0);
    if( _PAD(0,PADLright ) & padState )
    {
        if (CurrentSteering == 0 && PrevSteering == STEERING_NONE)
        {
            CurrentSteering = MinSteering;
        }
        else if (PrevSteering == STEERING_RIGHT)
        {
            CurrentSteering += SteeringStep;
            if (CurrentSteering > MaxSteering)
            {
                CurrentSteering = MaxSteering;
            }
        }
        bSteeringInThisFrame = 1;
        PrevSteering = STEERING_RIGHT;
    }
    if( _PAD(0,PADLleft ) & padState )
    {
        if (CurrentSteering == 0 && PrevSteering == STEERING_NONE)
        {
            CurrentSteering = MinSteering;
        }
        else if (PrevSteering == STEERING_LEFT)
        {
            CurrentSteering -= SteeringStep;
            if (CurrentSteering < -MaxSteering)
            {
                CurrentSteering = -MaxSteering;
            }
        }
        bSteeringInThisFrame = 1;
        PrevSteering = STEERING_LEFT;
    }
    if (!bSteeringInThisFrame)
    {
        PrevSteering = STEERING_NONE;
        if (CurrentSteering < 0)
        {
            CurrentSteering += DC_MIN(FrictionStep,DC_ABS(CurrentSteering));
        }
        else if (CurrentSteering > 0)
        {
            CurrentSteering -= DC_MIN(FrictionStep,DC_ABS(CurrentSteering));
        }
    }

    //Update rotation
    Player.rotation.vy = (-CurrentSteering * 400 ) / MaxSteering;

    Player.position.vx += CurrentSteering;

    updatePlayerImmunity();
    updateCollisions();
}

void updateCamera()
{
    targetCameraPosOffset.vx = Player.position.vx;
    targetCameraLookAtOffset.vx = Player.position.vx;

    cameraPosOffset.vx = DC_LERP(cameraPosOffset.vx, targetCameraPosOffset.vx, 512);
    cameraPosOffset.vy = DC_LERP(cameraPosOffset.vy, targetCameraPosOffset.vy, 512);
    cameraPosOffset.vz = DC_LERP(cameraPosOffset.vz, targetCameraPosOffset.vz, 512);
    cameraLookAtOffset.vx = DC_LERP(cameraLookAtOffset.vx, targetCameraLookAtOffset.vx, 512);
    cameraLookAtOffset.vy = DC_LERP(cameraLookAtOffset.vy, targetCameraLookAtOffset.vy, 512);
    cameraLookAtOffset.vz = DC_LERP(cameraLookAtOffset.vz, targetCameraLookAtOffset.vz, 512);
}

void updateCinematic()
{

    if(bCinematicMode)
    {
        currentCinematicTime += 32;
        if(currentCinematicTime >= totalCinematicDuration)
        {
            // Prevent cinematic going over total duration
            currentCinematicTime = totalCinematicDuration;
            // Stop cinematic mode
            bCinematicMode = 0;
        }
    }
}

void riverUpdateScene(tdGameMode* gameMode)
{
    CurrentFrame++;

    int prevLonchaIdx = lonchaOffset.vz / offsetToChangeLoncha;
    lonchaOffset.vz += scrollSpeed;
    dcBF_scrollAllShapes(&Broadphase,-scrollSpeed);
    int newLonchaIdx = lonchaOffset.vz / offsetToChangeLoncha;

    if (prevLonchaIdx != newLonchaIdx)
    {
        currentLoncha = nextLoncha;
        nextLoncha = GetNewLoncha();
        lonchaOffset.vz -= offsetToChangeLoncha;
        IncrementScrollSpeed();
    }

    if (lonchaOffset.vz > offsetToChangeLoncha >> 1 && currentPhisicsLoncha != nextLoncha && nextLoncha)
    {
        currentPhisicsLoncha = nextLoncha;
        ClearObstacles();
        registerLonchaObstacles(currentPhisicsLoncha);
    }

    updatePlayer();
    updateCamera();
     // Update cineamtic if needed
    updateCinematic();
}

void riverDrawScene(tdGameMode* gameMode, SDC_Render* render)
{
    RiverGameModeCamera = gameMode->camera;
    RiverGameModeRender = render;
    long cameraPosUnrealX = 0;
    long cameraPosUnrealY = -2000;
    long cameraPosUnrealZ = 1000;

    long distanceX = -cameraPosUnrealX;
    long distanceY = cameraPosUnrealZ;
    long distanceZ = -cameraPosUnrealY;

    if(bCinematicMode)
    {
        int numCinematicPoints = sizeof(introCinematicPath) / sizeof(introCinematicPath[0]);
        int durationPerPointPath = totalCinematicDuration / (numCinematicPoints-1);
        int currentPoint = currentCinematicTime / durationPerPointPath;
        int deltaInPoint = currentCinematicTime % durationPerPointPath;
        int scaler = 4096 / durationPerPointPath;
        int finalDeltaInPoint = deltaInPoint * scaler;

        int idx0 = currentPoint;
        int idx1 = currentPoint + 1 >= numCinematicPoints ? currentPoint : currentPoint + 1;
        
        // Camera Position
        SVECTOR p0 = introCinematicPath[idx0];
        SVECTOR p1 = introCinematicPath[idx1];
        VECTOR finalCameraPos = {DC_LERP(p0.vx,p1.vx, finalDeltaInPoint), DC_LERP(p0.vy,p1.vy, finalDeltaInPoint), DC_LERP(p0.vz,p1.vz, finalDeltaInPoint)};

        // Camera Look at
        SVECTOR l0 = introCinematicLookAt[idx0];
        SVECTOR l1 = introCinematicLookAt[idx1];
        VECTOR finalCameraLookAt = {DC_LERP(l0.vx,l1.vx, finalDeltaInPoint), DC_LERP(l0.vy,l1.vy, finalDeltaInPoint), DC_LERP(l0.vz,l1.vz, finalDeltaInPoint)};

        dcCamera_SetCameraPosition(gameMode->camera, finalCameraPos.vx, finalCameraPos.vy, finalCameraPos.vz);
        dcCamera_LookAt(gameMode->camera, &finalCameraLookAt);
    }
    else
    {
        VECTOR cameraPos = {distanceX + cameraPosOffset.vx, distanceY + cameraPosOffset.vy, distanceZ + cameraPosOffset.vz};
        VECTOR cameraLookAt = {cameraLookAtOffset.vx, cameraLookAtOffset.vy, cameraLookAtOffset.vz};
        dcCamera_SetCameraPosition(gameMode->camera, cameraPos.vx, cameraPos.vy, cameraPos.vz);
        dcCamera_LookAt(gameMode->camera, &cameraLookAt);
    }

    VECTOR NextLonchaOffset = lonchaOffset;
    NextLonchaOffset.vz -= offsetToChangeLoncha;

    // Draw the needed lonchas
    DrawLoncha(currentLoncha, lonchaOffset, render, gameMode->camera);
    DrawLoncha(nextLoncha, NextLonchaOffset, render, gameMode->camera);

    DrawBackground(gameMode, render);

    // If debugging draw collisions
    if(bEpicDebugMode)
    {
        DrawLonchaCollisions(currentLoncha, lonchaOffset, render, gameMode->camera);
        DrawLonchaCollisions(nextLoncha, NextLonchaOffset, render, gameMode->camera);
    }

    if (bPlayerVisible)
        DrawActor(&Player,render,gameMode->camera);
}

void DrawBackground(tdGameMode* gameMode, SDC_Render* render)
{
    dcRender_DrawBackground(render, &riverBackground);
}