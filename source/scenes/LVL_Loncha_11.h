#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "obstacle01.h"

#include "caixa.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

extern unsigned long _binary_assets_textures_casaTexture_tim_start[];

tdActor levelData_LVL_Loncha_11_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {2600,0,-1260}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {1120,0,-1260}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-2420,0,-1630}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-320,0,2210}, .meshData={.mesh=&caixa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_11_collisions[] = {
{.center={3270,0,0}, .halfSize={100,10000,4000}, .rotation={0,0,0}, .userData=1},
{.center={-3300,0,0}, .halfSize={100,10000,4000}, .rotation={0,0,0}, .userData=1},
{.center={-320,430,1900}, .halfSize={2019,302,706}, .rotation={0,0,0}, .userData=0},
{.center={2600,0,-1030}, .halfSize={706,302,706}, .rotation={0,0,0}, .userData=0},
{.center={1120,0,-1030}, .halfSize={706,302,706}, .rotation={0,0,0}, .userData=0},
{.center={-2420,0,-1400}, .halfSize={706,302,706}, .rotation={0,0,0}, .userData=0}
};
tdLoncha levelData_LVL_Loncha_11 = { .actors = levelData_LVL_Loncha_11_actors,  .numActors = sizeof(levelData_LVL_Loncha_11_actors) / sizeof(levelData_LVL_Loncha_11_actors[0]),
.collisions = levelData_LVL_Loncha_11_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_11_collisions) / sizeof(levelData_LVL_Loncha_11_collisions[0])
};