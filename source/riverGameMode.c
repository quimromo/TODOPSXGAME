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


tdLoncha currentLoncha;
tdLoncha nextLoncha;

VECTOR lonchaOffset = {0};

int scrollSpeed = 3;

void riverInitScene(tdGameMode* gameMode)
{
    dcCamera_SetScreenResolution(gameMode->camera, SCREEN_WIDTH, SCREEN_HEIGHT);
    lonchaOffset = VECTOR_ZERO;
}

void riverUpdateScene(tdGameMode* gameMode)
{
    lonchaOffset.vz += scrollSpeed;
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

    //DrawActorArrayOffset(currentLoncha.actors, currentLoncha.numActors, offset, render, gameMode->camera, 0);
    //DrawActorArrayOffset(nextLoncha.actors, nextLoncha.numActors, offset, render, gameMode->camera, 0);
    DrawActorArrayOffset(levelData_TestTile, 2, lonchaOffset, render, gameMode->camera, 0);
}