#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "obstacle01.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_05_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-10,0,-1370}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-10,0,1790}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-10,0,960}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-10,0,-600}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-10,0,-2190}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-10,0,160}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_05_collisions[] = {
{.center={3270,0,0}, .halfSize={100,10000,4000}, .rotation={0,0,0}, .userData=1},
{.center={-3300,0,0}, .halfSize={100,10000,4000}, .rotation={0,0,0}, .userData=1},
{.center={-10,0,2020}, .halfSize={706,302,706}, .rotation={0,0,0}, .userData=0},
{.center={-10,0,1190}, .halfSize={706,302,706}, .rotation={0,0,0}, .userData=0},
{.center={-10,0,-370}, .halfSize={706,302,706}, .rotation={0,0,0}, .userData=0},
{.center={-10,0,-1960}, .halfSize={706,302,706}, .rotation={0,0,0}, .userData=0},
{.center={-10,0,390}, .halfSize={706,302,706}, .rotation={0,0,0}, .userData=0},
{.center={-10,0,-1140}, .halfSize={706,302,706}, .rotation={0,0,0}, .userData=0}
};
tdLoncha levelData_LVL_Loncha_05 = { .actors = levelData_LVL_Loncha_05_actors,  .numActors = sizeof(levelData_LVL_Loncha_05_actors) / sizeof(levelData_LVL_Loncha_05_actors[0]),
.collisions = levelData_LVL_Loncha_05_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_05_collisions) / sizeof(levelData_LVL_Loncha_05_collisions[0])
};