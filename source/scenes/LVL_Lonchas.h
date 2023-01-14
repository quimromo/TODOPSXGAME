#pragma once
#include "../tdGameplay.h"
#include "lonchaBase.h"

extern unsigned long _binary_assets_textures_TilesetDelCampo_tim_start[];

tdActor levelData_LVL_Lonchas_actors[] = {
{.position = {0,0,0}, .meshData={.mesh=&lonchaBase_Mesh, .texture_tim=_binary_assets_textures_TilesetDelCampo_tim_start},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}}
};
tdLoncha levelData_LVL_Lonchas = { .actors = levelData_LVL_Lonchas_actors,  .numActors = sizeof(levelData_LVL_Lonchas_actors) / sizeof(levelData_LVL_Lonchas_actors[0])};