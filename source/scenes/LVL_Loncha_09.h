#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "casa.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

extern unsigned long _binary_assets_textures_casaTexture_tim_start[];

tdActor levelData_LVL_Loncha_09_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {60,0,-2260}, .meshData={.mesh=&casa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1660,0,1360}, .meshData={.mesh=&casa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {2090,0,1200}, .meshData={.mesh=&casa_Mesh, .texture_tim=_binary_assets_textures_casaTexture_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_09_collisions[] = {
{.center={3270,0,0}, .halfSize={100,10000,4000}, .rotation={0,0,0}, .userData=1},
{.center={-3300,0,0}, .halfSize={100,10000,4000}, .rotation={0,0,0}, .userData=1},
{.center={-1660,430,1100}, .halfSize={807,605,706}, .rotation={0,0,0}, .userData=0},
{.center={2090,430,940}, .halfSize={807,605,706}, .rotation={0,0,0}, .userData=0},
{.center={60,430,-2520}, .halfSize={807,605,706}, .rotation={0,0,0}, .userData=0}
};
tdLoncha levelData_LVL_Loncha_09 = { .actors = levelData_LVL_Loncha_09_actors,  .numActors = sizeof(levelData_LVL_Loncha_09_actors) / sizeof(levelData_LVL_Loncha_09_actors[0]),
.collisions = levelData_LVL_Loncha_09_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_09_collisions) / sizeof(levelData_LVL_Loncha_09_collisions[0])
};