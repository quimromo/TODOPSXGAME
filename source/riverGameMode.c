#include "riverGameMode.h"
#include "tdGameplay.h"
#include "dcMath.h"
#include "TestTile.h"
#include "assets/barkitu.h"

#include <libetc.h>

extern tdLoncha levelData_LVL_Lonchas;
extern unsigned long _binary_assets_textures_texturaEpica_tim_start[];

extern tdTIMDataHandler timData[];
SDC_Camera riverCamera;

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

tdLoncha currentLoncha;
tdLoncha nextLoncha;

VECTOR lonchaOffset = {0};

int offsetToChangeLoncha = 8900;

tdActor Player;
long CurrentSteering = 0;

// Movement Variables
int scrollSpeed = 65;
long SteeringStep = 8;
long FrictionStep = 4;

long MaxSteering = 40;
long MinSteering = 3;
int PrevSteering = STEERING_NONE;

extern int bEpicDebugMode;

tdLoncha GetNewLoncha(void)
{
    tdLoncha newLoncha = levelData_LVL_Lonchas;
    return newLoncha;
}

void riverInitScene(tdGameMode* gameMode)
{
    dcCamera_SetScreenResolution(gameMode->camera, SCREEN_WIDTH, SCREEN_HEIGHT);
    lonchaOffset = VECTOR_ZERO;
    lonchaOffset.vz -= offsetToChangeLoncha >> 2; // pivot is in the center, so we offset half the mesh
    currentLoncha = GetNewLoncha();
    nextLoncha = GetNewLoncha();

    Player.meshData.mesh = &barkitu_Mesh;
    Player.meshData.mesh->textureData = timData[1].textureData;
    Player.scale.vx = 4000;
    Player.scale.vy = 4000;
    Player.scale.vz = 4000;

    Player.position = VECTOR_ZERO;
    Player.rotation = SVECTOR_ZERO;

    Player.rotation.vy = 2000;

    Player.position.vz = 1000;
}

void updatePlayer()
{
    int bSteeringInThisFrame = 0;
    
    u_long padState = PadRead(0);
    if( _PAD(0,PADLright ) & padState )
    {
        if (CurrentSteering == 0)
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
        if (CurrentSteering == 0)
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

    Player.position.vx += CurrentSteering;
}

void riverUpdateScene(tdGameMode* gameMode)
{
    int prevLonchaIdx = (offsetToChangeLoncha >> 2) + lonchaOffset.vz / offsetToChangeLoncha;
    lonchaOffset.vz += scrollSpeed;
    int newLonchaIdx = (offsetToChangeLoncha >> 2) + lonchaOffset.vz / offsetToChangeLoncha;

    if (prevLonchaIdx != newLonchaIdx)
    {
        currentLoncha = nextLoncha;
        nextLoncha = GetNewLoncha();
        lonchaOffset.vz -= offsetToChangeLoncha;
    }

    updatePlayer();
}

void riverDrawScene(tdGameMode* gameMode, SDC_Render* render)
{
    long cameraPosUnrealX = 0;
    long cameraPosUnrealY = -2000;
    long cameraPosUnrealZ = 1000;

    long distanceX = -cameraPosUnrealX;
    long distanceY = cameraPosUnrealZ;
    long distanceZ = -cameraPosUnrealY;

    dcCamera_SetCameraPosition(gameMode->camera, distanceX, distanceY, distanceZ);
    dcCamera_LookAt(gameMode->camera, &VECTOR_ZERO);

    VECTOR NextLonchaOffset = lonchaOffset;
    NextLonchaOffset.vz -= offsetToChangeLoncha;

    // Draw the needed lonchas
    DrawLoncha(&currentLoncha, lonchaOffset, render, gameMode->camera);
    DrawLoncha(&nextLoncha, NextLonchaOffset, render, gameMode->camera);

    // If debugging draw collisions
    if(bEpicDebugMode)
    {
        DrawLonchaCollisions(&currentLoncha, lonchaOffset, render, gameMode->camera);
        DrawLonchaCollisions(&nextLoncha, NextLonchaOffset, render, gameMode->camera);
    }

    DrawActor(&Player,render,gameMode->camera);
}