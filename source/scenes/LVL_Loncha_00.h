#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_00_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_00_collisions[] = {
{.center={3270,0,0}, .halfSize={-100,4000,-10000}, .rotation={0,0,0}, .userData=1},
{.center={-3300,0,0}, .halfSize={-100,4000,-10000}, .rotation={0,0,0}, .userData=1}
};
tdLoncha levelData_LVL_Loncha_00 = { .actors = levelData_LVL_Loncha_00_actors,  .numActors = sizeof(levelData_LVL_Loncha_00_actors) / sizeof(levelData_LVL_Loncha_00_actors[0]),
.collisions = levelData_LVL_Loncha_00_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_00_collisions) / sizeof(levelData_LVL_Loncha_00_collisions[0])
};