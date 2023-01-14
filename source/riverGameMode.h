#ifndef RIVER_GAME_MODE_H
#define RIVER_GAME_MODE_H

#include "tdGameplay.h"

struct SDC_Render;

extern tdGameMode riverGameMode;

void riverInitScene(tdGameMode* gameMode);
void riverUpdateScene(tdGameMode* gameMode);
void riverDrawScene(tdGameMode* gameMode, SDC_Render* render);

#endif