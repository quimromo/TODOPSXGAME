#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "obstacle01.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_03_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-2750,0,2010}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1460,0,2010}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-90,0,2010}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {50,0,-2020}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {1370,0,-2020}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {2670,-120,-2020}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_03_collisions[] = {
{.center={-2750,0,2240}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-1460,0,2240}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-90,0,2240}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={50,0,-1790}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={1370,0,-1790}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={2670,-120,-1790}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0}
};
tdLoncha levelData_LVL_Loncha_03 = { .actors = levelData_LVL_Loncha_03_actors,  .numActors = sizeof(levelData_LVL_Loncha_03_actors) / sizeof(levelData_LVL_Loncha_03_actors[0]),
.collisions = levelData_LVL_Loncha_03_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_03_collisions) / sizeof(levelData_LVL_Loncha_03_collisions[0])
};