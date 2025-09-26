#pragma once

#include <string>
#include <vector>
#include "../src/PhysicsWorld.h"

// Forward declarations
namespace fbxsdk {
    class FbxManager;
    class FbxScene;
    class FbxNode;
}

class FbxImporter {
public:
    FbxImporter();
    ~FbxImporter();

    bool ImportScene(const std::string& filePath, PhysicsWorld& world);

private:
    void ProcessNode(fbxsdk::FbxNode* node, PhysicsWorld& world);

    fbxsdk::FbxManager* m_sdkManager = nullptr;
    fbxsdk::FbxScene* m_scene = nullptr;
};

