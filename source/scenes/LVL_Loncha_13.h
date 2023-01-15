#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "caixa.h"

#include "obstacle01.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

extern unsigned long _binary_assets_textures_casaTexture_tim_start[];

tdActor levelData_LVL_Loncha_13_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {2110,0,-1850}, .meshData={.mesh=&caixa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-2750,-100,1260}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1460,0,1260}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-260,0,1260}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_13_collisions[] = {
{.center={2110,430,-2160}, .halfSize={-1918,706,-302}, .rotation={0,0,0}, .userData=2},
{.center={-1460,0,1490}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-2750,-100,1490}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-260,0,1490}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0}
};
tdLoncha levelData_LVL_Loncha_13 = { .actors = levelData_LVL_Loncha_13_actors,  .numActors = sizeof(levelData_LVL_Loncha_13_actors) / sizeof(levelData_LVL_Loncha_13_actors[0]),
.collisions = levelData_LVL_Loncha_13_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_13_collisions) / sizeof(levelData_LVL_Loncha_13_collisions[0])
};