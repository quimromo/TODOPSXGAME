#include "riverGameMode.h"
#include "tdGameplay.h"
#include "dcMath.h"
#include "TestTile.h"

SDC_Camera riverCamera;

tdGameMode riverGameMode = 
{
    .camera = &riverCamera,
    .initFunction = &riverInitScene,
    .updateLoopFunction = &riverUpdateScene,
    .drawFunction = &riverDrawScene
};

void riverInitScene(tdGameMode* gameMode)
{
    dcCamera_SetScreenResolution(gameMode->camera, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void riverUpdateScene(tdGameMode* gameMode)
{
    int numActors = sizeof(levelData_TestTile) / sizeof(levelData_TestTile[0]);
    for (int i = 0; i < numActors; ++i)
    {
        int speed = 3;
        levelData_TestTile[i].position.vz += speed;
    }
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

    int numActors = sizeof(levelData_TestTile) / sizeof(levelData_TestTile[0]);
    DrawActorArray(levelData_TestTile, numActors, render, gameMode->camera, 1);
}