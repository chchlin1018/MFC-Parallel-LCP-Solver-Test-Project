#pragma once

#include "../src/PhysicsWorld.h"

// Forward declarations
namespace fbxsdk {
    class FbxMesh;
}

class FbxMeshConverter {
public:
    static bool Convert(fbxsdk::FbxMesh* fbxMesh, RigidBodyDesc& outDesc);
};

