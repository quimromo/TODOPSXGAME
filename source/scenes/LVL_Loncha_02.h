#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "obstacle01.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_02_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {1220,0,2010}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-2750,-90,2010}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {2710,-90,2010}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-150,0,-2020}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {1300,0,-2020}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {2720,-110,-2020}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1320,0,2010}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_02_collisions[] = {
{.center={-2750,-90,2240}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={2710,-90,2240}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-150,0,-1790}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={1300,0,-1790}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={2720,-110,-1790}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={1220,0,2240}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-1320,0,2240}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0}
};
tdLoncha levelData_LVL_Loncha_02 = { .actors = levelData_LVL_Loncha_02_actors,  .numActors = sizeof(levelData_LVL_Loncha_02_actors) / sizeof(levelData_LVL_Loncha_02_actors[0]),
.collisions = levelData_LVL_Loncha_02_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_02_collisions) / sizeof(levelData_LVL_Loncha_02_collisions[0])
};