// screw you code formatter, this one needs to stay on top
#include <stdlib.h>
// now we need to have libgte.h
#include <libgte.h>
// then, these can work; the psyq library is badly written and won't include what it uses
#include <libetc.h>
#include <libgpu.h>
#include <stdio.h>
#include <types.h>

#include "dcMemory.h"
#include "dcMath.h"
#include "dcCamera.h"
#include "dcRender.h"
#include "dcMisc.h"

#include "tdGameplay.h"
#include "riverGameMode.h"
#include "scenes/LVL_TestScene.h"
#include "scenes/LVL_Lonchas.h"

SDC_Render render;
SDC_DrawParams drawParams = {
    .tim = NULL,
    .constantColor = {255, 255, 255},
    .bLighting = 0,
    .bUseConstantColor = 1
};

SVECTOR rotation = {0};
VECTOR translation = {-512, 600, -512, 0};
MATRIX transform;

SDC_Camera camera;
long distance = 800;
long cameraHeight = 600;

tdGameMode* currentGameMode = NULL;

extern unsigned long _binary_tileset_tim_start[];
extern unsigned long _binary_assets_textures_waterTileset_tim_start[];

SVECTOR cameraOffset = {0, 0, 0};


void DrawHouses(SDC_Render* render, SDC_Camera* camera)
{
    long cameraPosUnrealX = 0;
    long cameraPosUnrealY = -2000;
    long cameraPosUnrealZ = 2000;

    long distanceX = -cameraPosUnrealX;
    long distanceY = cameraPosUnrealZ;
    long distanceZ = -cameraPosUnrealY;


    // Read pad state and move primitive
    u_long padState = PadRead(0);

    // input up/down will determine movement along the front vector of the cube
    if( _PAD(0,PADLup ) & padState )
    {
        cameraOffset.vz += -128;
    }
    if( _PAD(0,PADLdown ) & padState )
    {
        cameraOffset.vz += 128;
    }

    // Input right/left will determine rotation aroung Y axis.
    if( _PAD(0,PADLright ) & padState )
    {
        cameraOffset.vx += 128;
    }
    if( _PAD(0,PADLleft ) & padState )
    {
        cameraOffset.vx += -128;
    }


    VECTOR cameraLookAt = {cameraOffset.vx, cameraOffset.vy, cameraOffset.vz};
    dcCamera_SetCameraPosition(camera, distanceX+cameraOffset.vx, distanceY+cameraOffset.vy, distanceZ+cameraOffset.vz);
    dcCamera_LookAt(camera, &cameraLookAt);

    DrawActorArray(levelData_LVL_Lonchas.actors, levelData_LVL_Lonchas.numActors, render, camera, 0);
}

void HousesDrawFunction(tdGameMode* gameMode, SDC_Render* render)
{
    DrawHouses(render, gameMode->camera);
}

void HousesUpdateLoop(tdGameMode* gameMode)
{

}

void InitGameMode(tdGameMode* gameMode)
{
    if (gameMode->initFunction)
    {
        gameMode->initFunction(gameMode);
    }
}

void UpdateGameMode(tdGameMode* gameMode)
{
    if (gameMode->updateLoopFunction)
    {
        gameMode->updateLoopFunction(gameMode);
    }
}

void DrawGameMode(tdGameMode* gameMode, SDC_Render* render)
{
    if (gameMode->drawFunction)
    {
        gameMode->drawFunction(gameMode, render);
    }
}

int main(void) 
{
    dcMemory_Init();
    PadInit(0);
    InitGeom();

    
    CVECTOR bgColor = {60, 120, 120};
    dcRender_Init(&render, SCREEN_WIDTH, SCREEN_HEIGHT, bgColor, 4096, 16384*10, RENDER_MODE_PAL);
    dcCamera_SetScreenResolution(&camera, SCREEN_WIDTH, SCREEN_HEIGHT);
    dcCamera_SetCameraPosition(&camera, 0, cameraHeight, distance);
    dcCamera_LookAt(&camera, &VECTOR_ZERO);

    
    RotMatrix(&rotation, &transform);
    TransMatrix(&transform, &translation);


    TIM_IMAGE tim_tileset;
    dcRender_LoadTexture(&tim_tileset, _binary_assets_textures_waterTilesetSmall_tim_start);

    for(int i = 0; i<levelData_LVL_Lonchas.numActors; ++i)
    {
        levelData_LVL_Lonchas.actors[i].meshData.mesh->tim = &tim_tileset;
        InitializeActorBoundingBoxBasedOnMesh(&levelData_LVL_Lonchas.actors[i]);
    }

    tdGameMode housesGameMode;
    housesGameMode.camera = &camera;
    housesGameMode.initFunction = NULL;
    housesGameMode.updateLoopFunction = &HousesUpdateLoop;
    housesGameMode.drawFunction = &HousesDrawFunction;

    tdGameMode* gameModes[] = { &riverGameMode, &housesGameMode};
    u_long gameModeIdx = 0;
    u_long prevStartState = 0;
    InitGameMode(gameModes[gameModeIdx]);

    while (1)
    {

        // Cycle game-modes by pressing start
        u_long padState = PadRead(0);
        u_long startState = _PAD(0,PADstart ) & padState;
        if( !startState && prevStartState)
        {
            gameModeIdx++;
            int numGameModes = sizeof(gameModes) / sizeof(gameModes[0]);
            if(gameModeIdx >= numGameModes)
            {
                gameModeIdx = 0;
            }
            InitGameMode(gameModes[gameModeIdx]);
        }
        prevStartState = startState;

        // Update and draw the current game mode
        UpdateGameMode(gameModes[gameModeIdx]);
        DrawGameMode(gameModes[gameModeIdx], &render);

        dcRender_SwapBuffers(&render);
    }

    return 0;
}
