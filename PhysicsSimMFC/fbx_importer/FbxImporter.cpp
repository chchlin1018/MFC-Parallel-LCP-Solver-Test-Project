#include "pch.h"
#include "FbxImporter.h"
#include "FbxMeshConverter.h"
#include <fbxsdk.h>

FbxImporter::FbxImporter() {
    m_sdkManager = FbxManager::Create();
    FbxIOSettings* ios = FbxIOSettings::Create(m_sdkManager, IOSROOT);
    m_sdkManager->SetIOSettings(ios);
}

FbxImporter::~FbxImporter() {
    if (m_scene) {
        m_scene->Destroy();
    }
    if (m_sdkManager) {
        m_sdkManager->Destroy();
    }
}

bool FbxImporter::ImportScene(const std::string& filePath, PhysicsWorld& world) {
    m_scene = FbxScene::Create(m_sdkManager, "myScene");

    fbxsdk::FbxImporter* pImporter = fbxsdk::FbxImporter::Create(m_sdkManager, "");
    bool bSuccess = pImporter->Initialize(filePath.c_str(), -1, m_sdkManager->GetIOSettings());

    if (!bSuccess) {
        pImporter->Destroy();
        return false;
    }

    bSuccess = pImporter->Import(m_scene);
    pImporter->Destroy();

    if (!bSuccess) {
        return false;
    }

    // Convert axis system to OpenGL standard
    FbxAxisSystem::OpenGL.ConvertScene(m_scene);

    // Triangulate all meshes
    FbxGeometryConverter geometryConverter(m_sdkManager);
    geometryConverter.Triangulate(m_scene, true);

    FbxNode* rootNode = m_scene->GetRootNode();
    if (rootNode) {
        for (int i = 0; i < rootNode->GetChildCount(); i++) {
            ProcessNode(rootNode->GetChild(i), world);
        }
    }

    return true;
}

void FbxImporter::ProcessNode(FbxNode* node, PhysicsWorld& world) {
    if (!node) {
        return;
    }

    FbxNodeAttribute* attribute = node->GetNodeAttribute();
    if (attribute && attribute->GetAttributeType() == FbxNodeAttribute::eMesh) {
        FbxMesh* mesh = static_cast<FbxMesh*>(attribute);
        RigidBodyDesc desc;
        if (FbxMeshConverter::Convert(mesh, desc)) {
            world.AddRigidBody(desc);
        }
    }

    for (int i = 0; i < node->GetChildCount(); i++) {
        ProcessNode(node->GetChild(i), world);
    }
}

