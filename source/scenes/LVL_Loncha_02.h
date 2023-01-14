#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "obstacle01.h"

extern unsigned long _binary_assets_textures_waterTilesetFinal_tim_start[];

tdActor levelData_LVL_Loncha_02_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-2750,0,2010}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1320,0,2010}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {2470,0,2010}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-380,0,-2020}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {1070,0,-2020}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {2490,0,-2020}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {980,0,2010}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetFinal_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Loncha_02_collisions[] = {
{.center={-2750,0,2010}, .halfSize={700,700,700}, .rotation={0,0,0}},
{.center={3270,0,0}, .halfSize={100,5000,4000}, .rotation={0,0,0}},
{.center={-3300,0,0}, .halfSize={100,5000,4000}, .rotation={0,0,0}},
{.center={2470,0,2010}, .halfSize={700,700,700}, .rotation={0,0,0}},
{.center={-380,0,-2020}, .halfSize={700,700,700}, .rotation={0,0,0}},
{.center={1070,0,-2020}, .halfSize={700,700,700}, .rotation={0,0,0}},
{.center={2490,0,-2020}, .halfSize={700,700,700}, .rotation={0,0,0}},
{.center={980,0,2010}, .halfSize={700,700,700}, .rotation={0,0,0}},
{.center={-1320,0,2010}, .halfSize={700,700,700}, .rotation={0,0,0}}
};
tdLoncha levelData_LVL_Loncha_02 = { .actors = levelData_LVL_Loncha_02_actors,  .numActors = sizeof(levelData_LVL_Loncha_02_actors) / sizeof(levelData_LVL_Loncha_02_actors[0]),
.collisions = levelData_LVL_Loncha_02_collisions,  .numCollisions = sizeof(levelData_LVL_Loncha_02_collisions) / sizeof(levelData_LVL_Loncha_02_collisions[0])
};