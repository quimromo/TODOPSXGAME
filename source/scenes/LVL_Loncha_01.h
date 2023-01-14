#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "obstacle01.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_01_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {2170,0,1470}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 444, 0}},
{.position = {-800,0,-680}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_01_collisions[] = {
{.center={-800,0,-680}, .halfSize={700,700,700}, .rotation={0,0,0}},
{.center={3270,0,0}, .halfSize={100,5000,4000}, .rotation={0,0,0}},
{.center={-3300,0,0}, .halfSize={100,5000,4000}, .rotation={0,0,0}},
{.center={2170,0,1470}, .halfSize={700,700,700}, .rotation={0,444,0}}
};
tdLoncha levelData_LVL_Loncha_01 = { .actors = levelData_LVL_Loncha_01_actors,  .numActors = sizeof(levelData_LVL_Loncha_01_actors) / sizeof(levelData_LVL_Loncha_01_actors[0]),
.collisions = levelData_LVL_Loncha_01_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_01_collisions) / sizeof(levelData_LVL_Loncha_01_collisions[0])
};