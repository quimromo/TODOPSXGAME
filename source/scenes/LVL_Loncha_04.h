#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "obstacle01.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_04_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1330,0,-2020}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1530,0,1900}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {1300,0,2480}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {2740,-200,2010}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-2780,0,-2020}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {2220,-70,-2020}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_04_collisions[] = {
{.center={-1530,0,2130}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={1300,0,2710}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={2740,-200,2240}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-2780,0,-1790}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={2220,-70,-1790}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-1330,0,-1790}, .halfSize={-636,706,-302}, .rotation={0,0,0}, .userData=0}
};
tdLoncha levelData_LVL_Loncha_04 = { .actors = levelData_LVL_Loncha_04_actors,  .numActors = sizeof(levelData_LVL_Loncha_04_actors) / sizeof(levelData_LVL_Loncha_04_actors[0]),
.collisions = levelData_LVL_Loncha_04_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_04_collisions) / sizeof(levelData_LVL_Loncha_04_collisions[0])
};