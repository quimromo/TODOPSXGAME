#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "obstacle01.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_06_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1700,0,2770}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1700,0,1260}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1700,0,-120}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1700,0,-1490}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-10,0,1910}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-10,0,400}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-10,0,-980}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-10,0,-2350}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_06_collisions[] = {
{.center={3270,0,0}, .halfSize={-100,4000,-10000}, .rotation={0,0,0}, .userData=1},
{.center={-3300,0,0}, .halfSize={-100,4000,-10000}, .rotation={0,0,0}, .userData=1},
{.center={-1700,0,3000}, .halfSize={-555,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-1700,0,1490}, .halfSize={-555,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-1700,0,110}, .halfSize={-555,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-1700,0,-1260}, .halfSize={-555,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-10,0,2140}, .halfSize={-555,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-10,0,630}, .halfSize={-555,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-10,0,-750}, .halfSize={-555,706,-302}, .rotation={0,0,0}, .userData=0},
{.center={-10,0,-2120}, .halfSize={-555,706,-302}, .rotation={0,0,0}, .userData=0}
};
tdLoncha levelData_LVL_Loncha_06 = { .actors = levelData_LVL_Loncha_06_actors,  .numActors = sizeof(levelData_LVL_Loncha_06_actors) / sizeof(levelData_LVL_Loncha_06_actors[0]),
.collisions = levelData_LVL_Loncha_06_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_06_collisions) / sizeof(levelData_LVL_Loncha_06_collisions[0])
};