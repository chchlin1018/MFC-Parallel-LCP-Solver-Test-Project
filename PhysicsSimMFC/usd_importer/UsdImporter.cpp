_Pragma('''#include "pch.h"''')
_Pragma('''#include "UsdImporter.h"''')
_Pragma('''#include "UsdGeometryConverter.h"''')

_Pragma('''#include "pxr/usd/usd/stage.h"''')
_Pragma('''#include "pxr/usd/usdGeom/mesh.h"''')

_Pragma('''PXR_NAMESPACE_USING_DIRECTIVE''')

UsdImporter::UsdImporter() = default;

UsdImporter::~UsdImporter() {
    if (m_stage) {
        delete m_stage;
    }
}

bool UsdImporter::ImportScene(const std::string& filePath, PhysicsWorld& world) {
    m_stage = UsdStage::Open(filePath);
    if (!m_stage) {
        return false;
    }

    for (const auto& prim : m_stage->Traverse()) {
        ProcessPrim(prim, world);
    }

    return true;
}

void UsdImporter::ProcessPrim(const UsdPrim& prim, PhysicsWorld& world) {
    if (prim.IsA<UsdGeomMesh>()) {
        UsdGeomMesh mesh(prim);
        RigidBodyDesc desc;
        if (UsdGeometryConverter::Convert(mesh, desc)) {
            world.AddRigidBody(desc);
        }
    }
}

