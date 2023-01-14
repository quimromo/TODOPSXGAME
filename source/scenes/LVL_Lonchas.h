#pragma once
#include "tdGameplay.h"
#include "lonchaBase.h"

#include "barkitu.h"

#include "obstacle01.h"

extern unsigned long _binary_assets_textures_waterTilesetSmall_tim_start[];

extern unsigned long _binary_assets_textures_texturaEpica_tim_start[];

tdActor levelData_LVL_Lonchas_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_waterTilesetSmall_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {430,0,3260}, .meshData={.mesh=&barkitu_Mesh, .texture_tim=_binary_assets_textures_texturaEpica_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 2000, 0}},
{.position = {-800,0,-680}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetSmall_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {1810,0,2900}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetSmall_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {2090,0,-3720}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetSmall_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-2030,0,2900}, .meshData={.mesh=&obstacle01_Mesh, .texture_tim=_binary_assets_textures_waterTilesetSmall_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
SDC_OOBB levelData_LVL_Lonchas_collisions[] = {
{.center={2090,0,-3720}, .halfSize={-700,700,-700}, .rotation={0,0,0}},
{.center={1810,0,2900}, .halfSize={-700,700,-700}, .rotation={0,0,0}},
{.center={-800,0,-680}, .halfSize={-700,700,-700}, .rotation={0,0,0}},
{.center={-2030,0,2900}, .halfSize={-700,700,-700}, .rotation={0,0,0}},
{.center={3270,0,0}, .halfSize={-100,4000,-5000}, .rotation={0,0,0}},
{.center={-3300,0,0}, .halfSize={-100,4000,-5000}, .rotation={0,0,0}}
};
tdLoncha levelData_LVL_Lonchas = { .actors = levelData_LVL_Lonchas_actors,  .numActors = sizeof(levelData_LVL_Lonchas_actors) / sizeof(levelData_LVL_Lonchas_actors[0]),
.collisions = levelData_LVL_Lonchas_collisions,  .numCollisions = sizeof(levelData_LVL_Lonchas_collisions) / sizeof(levelData_LVL_Lonchas_collisions[0])
};