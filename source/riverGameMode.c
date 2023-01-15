#include "riverGameMode.h"
#include "tdGameplay.h"
#include "dcMath.h"
#include "TestTile.h"
#include "assets/td_VAPOR_hull.h"
#include "LVL_Loncha_00.h"
#include "LVL_Loncha_01.h"
#include "LVL_Loncha_02.h"
#include "LVL_Loncha_03.h"
#include "LVL_Loncha_04.h"
#include "LVL_Loncha_05.h"
#include "LVL_Loncha_06.h"
#include "LVL_Loncha_07.h"
#include "LVL_Loncha_08.h"
#include "LVL_Loncha_09.h"
#include "LVL_Loncha_10.h"
#include "LVL_Loncha_11.h"
#include "LVL_NewLoncha_00.h"
#include "tdConfig.h"
#include <libetc.h>
#include <stdio.h>

#define IMMUNITY_BLINK_RATE 3
#define HIT_IMMUNITY_DURATION 60
#define WALL HIT_IMMUNITY_DURATION 30

#define COLLISION_FRONT_OFFSET 400

#define MAX_OBSTACLES_PER_LONCHA 50
#define MIN_SCROLL_SPEED 65

#define PLAYER_HITBOX_SIZE 30

#define JUMP_FORCE 300
#define GRAVITY_FORCE 50

#define USER_DATA_WALL 1

extern SDC_Broadphase Broadphase;

SDC_Camera* RiverGameModeCamera;
SDC_Render* RiverGameModeRender;

int bLoadedPhisicsLoncha = 0;

extern tdLoncha levelData_LVL_Lonchas;
extern unsigned long _binary_assets_textures_texturaEpica_tim_start[];

extern tdTIMDataHandler timData[];
SDC_Camera riverCamera;

SDC_Texture riverBackground;
int riverBackgroundInitialized = 0;
extern unsigned long _binary_assets_textures_sky_psx_tim_start[];

SDC_Texture emptyLifeTexture;
SDC_Texture fillLifeTexture;
extern unsigned long _binary_assets_textures_empty_life_tim_start[];
extern unsigned long _binary_assets_textures_fill_life_tim_start[];

unsigned CurrentObstacles[MAX_OBSTACLES_PER_LONCHA];
unsigned numObstacles;

unsigned totalDistance = 0;

extern unsigned long _binary_assets_textures_capitan_tim_start[];
tdRiverUI riverUI;

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
long VerticalAcceleration = 0;

int MaxLives = 3;
int NumLives = 0;

// Movement Variables
int scrollSpeed = 65;

int maxScrollSpeed = 270;
int scrollSpeedIncreasePerLoncha = 30;
int scrollSpeedIncreasePerLonchaAfterFirstHit = 50;
long SteeringStep = 100;
long FrictionStep = 70;

short MaxRotationAngle = 30;
long MaxSteering = 300;
long MinSteering = 40;
int PrevSteering = STEERING_NONE;

int currentCinematicTime = 0;
int totalCinematicDuration = 3000;
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
extern unsigned long _binary_assets_textures_T_Vapor_hull_tim_start[];

// Used to select from available lonchas
int maxLonchaFromList = 7;

// Order matters
tdLoncha* lonchasList[] = {
    &levelData_LVL_Loncha_00,
    &levelData_LVL_Loncha_01,
    &levelData_LVL_Loncha_02,
    &levelData_LVL_Loncha_03,
    &levelData_LVL_Loncha_04,
    &levelData_LVL_Loncha_05,
    &levelData_LVL_Loncha_06, // 7

    &levelData_LVL_Loncha_08,
    &levelData_LVL_Loncha_10, // 9

    &levelData_LVL_Loncha_07,
    &levelData_LVL_Loncha_09,
    &levelData_LVL_Loncha_11  // 12
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
            SDC_Texture* textureData = GetTextureDataAndLoadIfNeeded( loncha->actors[j].meshData.texture_tim);
            loncha->actors[j].meshData.mesh->textureData = *textureData;
            
            // Initialize bounding box
            InitializeActorBoundingBoxBasedOnMesh(&loncha->actors[j]);
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
        shape.userData = Loncha->collisions[i].userData;

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
    int numLonchasInList = sizeof(lonchasList) / sizeof(lonchasList[0]);
    idInLonchasList = RandomBetween(1, numLonchasInList < maxLonchaFromList ? numLonchasInList : maxLonchaFromList);
}

tdLoncha* GetNewLoncha(void)
{
    tdLoncha* newLoncha = lonchasList[idInLonchasList];
    IncrementLonchasListId();
    
    return newLoncha;
}

void CorrectUserLocation()
{
    CurrentSteering = Player.position.vx < 0 ? MaxSteering : -MaxSteering; 
}

void DamagePlayer(void)
{
    --NumLives;

    if (NumLives <= 0)
    {
        // TODO: game over
    }
}

void OnPlayerObstacleHit(SDC_Shape* Other)
{
    if (Other->userData == USER_DATA_WALL)
    {
        //At the moment harcoded in PlayerUpdate
        //CorrectUserLocation();
    }
    else
    {
        if (bImmune || VerticalAcceleration!=0)
            return;
        CurrImmunityFrames = 0;
        ImmunityDuration = HIT_IMMUNITY_DURATION;
        bImmune = 1;
        scrollSpeed = MIN_SCROLL_SPEED;
        DamagePlayer();

        // Increase scroll speed per loncha after first hit to get back to action faster
        scrollSpeedIncreasePerLoncha = scrollSpeedIncreasePerLonchaAfterFirstHit;
    }
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

        dcRender_LoadTexture(&timImage, _binary_assets_textures_empty_life_tim_start);
        emptyLifeTexture.mode = timImage.mode;
        emptyLifeTexture.crect = *timImage.crect;
        emptyLifeTexture.prect = *timImage.prect;

        dcRender_LoadTexture(&timImage, _binary_assets_textures_fill_life_tim_start);
        fillLifeTexture.mode = timImage.mode;
        fillLifeTexture.crect = *timImage.crect;
        fillLifeTexture.prect = *timImage.prect;

        dcRender_LoadTexture(&timImage, _binary_assets_textures_capitan_tim_start);
        
        riverUI.captainDefaultAnim.timImage.mode = timImage.mode;
        riverUI.captainDefaultAnim.timImage.crect = *timImage.crect;
        riverUI.captainDefaultAnim.timImage.prect = *timImage.prect;
        
        //riverUI.captainDefaultAnim.frames 
        riverUI.captainDefaultAnim.speed = 0;
        riverUI.captainDefaultAnim.nframes = 1;

        static SDC_SpriteFrame defaultCptAnimFrames[] = { {0, 0, 128, 128} };
        riverUI.captainDefaultAnim.frames = &defaultCptAnimFrames[0];
        riverUI.captainDrawLocation.x = 5;
        riverUI.captainDrawLocation.y = 171;
        riverUI.captainDrawLocation.h = 64;
        riverUI.captainDrawLocation.w = 128;

        riverUI.captainSprite.currAnimation = &riverUI.captainDefaultAnim;
        riverUI.captainSprite.currAnimFrame = 0;
        riverUI.captainSprite.currCounter = 0;

        riverBackgroundInitialized = 1;
    }
    
    InitializeLonchas();

    dcCamera_SetScreenResolution(gameMode->camera, SCREEN_WIDTH, SCREEN_HEIGHT);
    lonchaOffset = VECTOR_ZERO;
    currentLoncha = GetNewLoncha();
    nextLoncha = GetNewLoncha();
    NumLives = MaxLives;

    Player.meshData.mesh = &td_VAPOR_hull_Mesh;
    Player.meshData.texture_tim = _binary_assets_textures_T_Vapor_hull_tim_start;
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
    sphereShape.sphere.center.vz -= COLLISION_FRONT_OFFSET;
    sphereShape.sphere.radius = PLAYER_HITBOX_SIZE;

    SDC_Shape* CollResult = dcBF_shapeCollides(&Broadphase, &sphereShape ,RiverGameModeRender, RiverGameModeCamera );
    if( CollResult )
    {
        OnPlayerObstacleHit(CollResult);
    }
}

void updatePlayer()
{
    int bSteeringInThisFrame = 0;
    int FrameSteeringStep = VerticalAcceleration==0 ? SteeringStep : SteeringStep >> 2;
    
    u_long padState = PadRead(0);
    if( _PAD(0,PADLright ) & padState )
    {
        if (CurrentSteering == 0 && PrevSteering == STEERING_NONE)
        {
            CurrentSteering = MinSteering;
        }
        else if (PrevSteering == STEERING_RIGHT)
        {
            CurrentSteering += FrameSteeringStep;
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
            CurrentSteering -= FrameSteeringStep;
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

    if( _PAD(0,PADRright ) & padState && Player.position.vy == 0)
    {
        VerticalAcceleration = JUMP_FORCE;
    }

    if (Player.position.vy > 0)
    {   
        if (VerticalAcceleration> 0)
        {
            VerticalAcceleration-=GRAVITY_FORCE;
        }else{
            VerticalAcceleration-=GRAVITY_FORCE >> 2;
        }
    }

    Player.position.vy += VerticalAcceleration;

    if (Player.position.vy < 0)
    {
        Player.position.vy = 0;
        VerticalAcceleration = 0;
    }
    //Update rotation
    Player.rotation.vy = (-CurrentSteering * 400 ) / MaxSteering;
    Player.rotation.vx = (VerticalAcceleration );

    Player.position.vx += CurrentSteering;

    updatePlayerImmunity();
    updateCollisions();

    //hack for the side walls
    if (DC_ABS(Player.position.vx) > 3300)
    {
        CorrectUserLocation();
    }

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

    if (!bCinematicMode)
    {
        totalDistance += scrollSpeed >> 3;

        // If you change lonchas list you may want to change this
        if(totalDistance > 15000)
        {
            maxLonchaFromList = 12;
        }
        else if (totalDistance > 8000)
        {
            maxLonchaFromList = 9;
        }
    }

    if (prevLonchaIdx != newLonchaIdx)
    {
        currentLoncha = nextLoncha;
        nextLoncha = GetNewLoncha();
        lonchaOffset.vz -= offsetToChangeLoncha;
        IncrementScrollSpeed();
        bLoadedPhisicsLoncha = 0;
    }

    if (lonchaOffset.vz > offsetToChangeLoncha >> 1 && !bLoadedPhisicsLoncha && nextLoncha)
    {
        bLoadedPhisicsLoncha = 1;
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

    riverDrawUI(gameMode, render);

    // If debugging draw collisions
    if(bEpicDebugMode)
    {
        DrawLonchaCollisions(currentLoncha, lonchaOffset, render, gameMode->camera);
        DrawLonchaCollisions(nextLoncha, NextLonchaOffset, render, gameMode->camera);
    }

    if (bPlayerVisible)
    {
        VECTOR playerOffset = {0,80,0};
        DrawActorOffset(&Player, playerOffset, render,gameMode->camera);
    }

    FntPrint("Total distance: %d\n", totalDistance);
}

void riverDrawLifesUI(tdGameMode* gameMode, SDC_Render* render)
{
    RECT lifePosition = {0};
    lifePosition.h = 16;
    lifePosition.w = lifePosition.h << 1;

    for (int i = 0; i < MaxLives; ++i)
    {
        lifePosition.x = 5 + 40 * i;
        lifePosition.y = 171 - 20;

        SDC_Texture* renderTex = NumLives > i ? &fillLifeTexture : &emptyLifeTexture;
        dcRender_DrawQuad(render, renderTex, &lifePosition);
    }
}

void riverDrawUI(tdGameMode* gameMode, SDC_Render* render)
{
    dcRender_DrawQuad(render, &riverUI.captainDefaultAnim.timImage, &riverUI.captainDrawLocation);
    riverDrawLifesUI(gameMode, render);
}

void DrawBackground(tdGameMode* gameMode, SDC_Render* render)
{
    dcRender_DrawBackground(render, &riverBackground);
}