#pragma once

#include <string>
#include "../src/PhysicsWorld.h"

// Forward declarations
namespace pxr {
    class UsdStage;
    class UsdPrim;
}

class UsdImporter {
public:
    UsdImporter();
    ~UsdImporter();

    bool ImportScene(const std::string& filePath, PhysicsWorld& world);

private:
    void ProcessPrim(const pxr::UsdPrim& prim, PhysicsWorld& world);

    pxr::UsdStage* m_stage = nullptr;
};

