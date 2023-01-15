#ifndef RIVER_GAME_MODE_H
#define RIVER_GAME_MODE_H

#include "tdGameplay.h"
#include "dcSprite.h"

struct SDC_Render;

extern tdGameMode riverGameMode;

void riverInitScene(tdGameMode* gameMode);
void riverUpdateScene(tdGameMode* gameMode);
void riverDrawScene(tdGameMode* gameMode, SDC_Render* render);

void riverDrawUI(tdGameMode* gameMode, SDC_Render* render);

typedef struct
{
    SDC_Sprite captainSprite;
    SDC_SpriteAnimation captainDefaultAnim;
    RECT captainDrawLocation;

    /* data */
} tdRiverUI;


#endif