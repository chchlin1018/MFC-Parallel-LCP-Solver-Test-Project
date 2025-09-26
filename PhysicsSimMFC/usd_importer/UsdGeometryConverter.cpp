_Pragma("once")

#include "pch.h"
#include "UsdGeometryConverter.h"
#include "pxr/usd/usdGeom/mesh.h"
#include "pxr/base/vt/array.h"

PXR_NAMESPACE_USING_DIRECTIVE

bool UsdGeometryConverter::Convert(const UsdGeomMesh& usdMesh, RigidBodyDesc& outDesc) {
    if (!usdMesh) {
        return false;
    }

    // Get vertices
    VtArray<GfVec3f> points;
    usdMesh.GetPointsAttr().Get(&points);
    if (points.empty()) {
        return false;
    }

    std::vector<float3> vertices(points.size());
    for (size_t i = 0; i < points.size(); ++i) {
        vertices[i] = float3(points[i][0], points[i][1], points[i][2]);
    }

    // Get indices
    VtArray<int> faceVertexCounts;
    VtArray<int> faceVertexIndices;
    usdMesh.GetFaceVertexCountsAttr().Get(&faceVertexCounts);
    usdMesh.GetFaceVertexIndicesAttr().Get(&faceVertexIndices);

    if (faceVertexCounts.empty() || faceVertexIndices.empty()) {
        return false;
    }

    std::vector<int> indices;
    int currentIndex = 0;
    for (int count : faceVertexCounts) {
        if (count != 3) {
            // We only support triangulated meshes
            return false;
        }
        for (int i = 0; i < count; ++i) {
            indices.push_back(faceVertexIndices[currentIndex++]);
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

