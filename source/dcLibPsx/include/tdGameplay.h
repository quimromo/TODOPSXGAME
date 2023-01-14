#pragma once
#include <sys/types.h>
#include <libgte.h>
#include <stdint.h>
#include <libgpu.h>
#include <dcrender.h>
#include "dcCamera.h"

struct tdActor;
struct tdMesh;
struct tdPhysicsData;
struct tdBoundingBox;
struct tdGameMode;
struct SDC_Render;

typedef void (*InitFunction)(struct tdGameMode* gameMode);
typedef void (*UpdateLoopFunction)(struct tdGameMode*);
typedef void (*DrawFunction)(struct tdGameMode*, SDC_Render* render);

typedef struct tdGameMode{
    SDC_Camera* camera;
    InitFunction initFunction;
    UpdateLoopFunction updateLoopFunction;
    DrawFunction drawFunction;
    char* name; 
} tdGameMode;

// Holds bounding box of the actor
typedef struct tdBoundingBox{
    SVECTOR min;
    SVECTOR max;
} tdBoundingBox;

// Physics data such as velocity, gravity or bounding box
typedef struct tdPhysicsData{
    SVECTOR velocity;
    int mass;
    tdBoundingBox boundingBox;
} tdPhysicsData;

// Actual mesh data, mesh + texture
typedef struct tdMesh{
    SDC_Mesh3D* mesh;
    u_long* texture_tim;
} tdMesh;

// Basic actor with transform, physics data and mesh data
typedef struct tdActor{
    VECTOR position;
    SVECTOR rotation;
    VECTOR scale;
    tdPhysicsData physicsData;
    tdMesh meshData;
} tdActor;

typedef struct tdCollisionPlane
{

} tdCollisionPlane;

typedef struct tdLoncha{
    tdActor* actors;
    int numActors;
    tdCollisionPlane* collisions;
    int numCollisions;
} tdLoncha;

// Draws and actor using a camera
void DrawActor(tdActor* actor, SDC_Render* render,  SDC_Camera* camera);
// Draws bounding box of an actor given a camera
void DrawActorBoundingBox(tdActor* actor, SDC_Render* render,  SDC_Camera* camera);
// Calculates the actor bounding box automatically
// Warning, if mesh data is null this will crash
void InitializeActorBoundingBoxBasedOnMesh(tdActor* actor);
// Computs the actor transform taking into account position/rotation/scale
void GetActorTransform(tdActor* actor, MATRIX* outTransform);
// Draws an array of actors
void DrawActorArray(tdActor actorArray[], int numActors, SDC_Render* render, SDC_Camera* camera, int bDrawBoundingBox);