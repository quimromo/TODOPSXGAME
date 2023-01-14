#include "riverGameMode.h"
#include "tdGameplay.h"
#include "dcMath.h"
#include "TestTile.h"

extern tdLoncha levelData_LVL_Lonchas;

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

int scrollSpeed = 9;
int offsetToChangeLoncha = 8900;

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

    DrawActorArrayOffset(currentLoncha.actors, currentLoncha.numActors, lonchaOffset, render, gameMode->camera, 1);
    DrawActorArrayOffset(nextLoncha.actors, nextLoncha.numActors, NextLonchaOffset, render, gameMode->camera, 1);
    //DrawActorArrayOffset(levelData_TestTile, 2, lonchaOffset, render, gameMode->camera, 0);
}