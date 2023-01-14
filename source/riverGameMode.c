#include "riverGameMode.h"
#include "tdGameplay.h"
#include "dcMath.h"
#include "TestTile.h"
#include "assets/barkitu.h"

#include <libetc.h>
#include <stdio.h>

#define IMMUNITY_BLINK_RATE 3
#define HIT_IMMUNITY_DURATION 60
#define WALL HIT_IMMUNITY_DURATION 30

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

unsigned long CurrentFrame = 0;

tdLoncha currentLoncha;
tdLoncha nextLoncha;

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
long SteeringStep = 8;
long FrictionStep = 4;

short MaxRotationAngle = 30;
long MaxSteering = 40;
long MinSteering = 3;
int PrevSteering = STEERING_NONE;

extern int bEpicDebugMode;
extern unsigned long _binary_assets_textures_texturaEpica_tim_start[];

tdLoncha GetNewLoncha(void)
{
    tdLoncha newLoncha = levelData_LVL_Lonchas;
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
    dcCamera_SetScreenResolution(gameMode->camera, SCREEN_WIDTH, SCREEN_HEIGHT);
    lonchaOffset = VECTOR_ZERO;
    lonchaOffset.vz -= offsetToChangeLoncha >> 2; // pivot is in the center, so we offset half the mesh
    currentLoncha = GetNewLoncha();
    nextLoncha = GetNewLoncha();

    Player.meshData.mesh = &barkitu_Mesh;
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
    Player.rotation.vy = -CurrentSteering * 7;

    Player.position.vx += CurrentSteering;

    updatePlayerImmunity();
}

void riverUpdateScene(tdGameMode* gameMode)
{
    CurrentFrame++;

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

    if (bPlayerVisible)
        DrawActor(&Player,render,gameMode->camera);
}