#pragma once

#include "../src/PhysicsWorld.h"

// Forward declarations
namespace pxr {
    class UsdGeomMesh;
}

class UsdGeometryConverter {
public:
    static bool Convert(const pxr::UsdGeomMesh& usdMesh, RigidBodyDesc& outDesc);
};

