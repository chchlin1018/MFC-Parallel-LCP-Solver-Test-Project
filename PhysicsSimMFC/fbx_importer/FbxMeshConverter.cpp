#include "FbxMeshConverter.h"
#include <fbxsdk.h>

bool FbxMeshConverter::Convert(fbxsdk::FbxMesh* fbxMesh, RigidBodyDesc& outDesc) {
    if (!fbxMesh) {
        return false;
    }

    // Get vertices
    int vertexCount = fbxMesh->GetControlPointsCount();
    if (vertexCount == 0) {
        return false;
    }

    std::vector<float3> vertices(vertexCount);
    for (int i = 0; i < vertexCount; ++i) {
        FbxVector4 v = fbxMesh->GetControlPointAt(i);
        vertices[i] = float3((float)v[0], (float)v[1], (float)v[2]);
    }

    // Get indices
    int polygonCount = fbxMesh->GetPolygonCount();
    if (polygonCount == 0) {
        return false;
    }

    std::vector<int> indices;
    indices.reserve(polygonCount * 3);
    for (int i = 0; i < polygonCount; ++i) {
        if (fbxMesh->GetPolygonSize(i) != 3) {
            // We only support triangulated meshes
            continue;
        }
        for (int j = 0; j < 3; ++j) {
            indices.push_back(fbxMesh->GetPolygonVertex(i, j));
        }
    }

    if (indices.empty()) {
        return false;
    }

    // Create shape description
    outDesc.shape.type = ShapeType::ConvexHull;
    outDesc.shape.vertices = vertices;
    outDesc.shape.indices = indices;

    // Set default material and mass
    outDesc.material.restitution = 0.5f;
    outDesc.material.friction = 0.5f;
    outDesc.mass = 1.0f;

    return true;
}

