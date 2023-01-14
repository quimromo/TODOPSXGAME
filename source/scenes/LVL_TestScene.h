#pragma once
#include "tdGameplay.h"
#include "CasaDelCampo.h"

tdActor levelData_LVL_TestScene[] = {
{.position = {0,0,0}, .meshData={.mesh=&CasaDelCampo_Mesh},
.scale = {4000,4000,4000},
.rotation={0, 0, 0}},
{.position = {-1090,0,-400}, .meshData={.mesh=&CasaDelCampo_Mesh},
.scale = {4000,4000,4000},
.rotation={0, -1000, 0}},
{.position = {780,0,0}, .meshData={.mesh=&CasaDelCampo_Mesh},
.scale = {4000,4000,4000},
.rotation={0, 0, -222}},
{.position = {0,-700,900}, .meshData={.mesh=&CasaDelCampo_Mesh},
.scale = {4000,4000,4000},
.rotation={333, 0, 0}}
};