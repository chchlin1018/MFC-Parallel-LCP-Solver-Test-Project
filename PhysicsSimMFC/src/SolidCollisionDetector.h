#pragma once

#include "ICollisionDetector.h"
#include <SOLID.h>
#include <unordered_map>

class SolidCollisionDetector : public ICollisionDetector {
public:
    SolidCollisionDetector();
    ~SolidCollisionDetector() override;

    void AddRigidBody(RigidBody* body) override;
    void RemoveRigidBody(RigidBody* body) override;
    void DetectCollisions(std::vector<Contact>& contacts) override;
    void UpdateRigidBodyTransform(RigidBody* body) override;

private:
    DT_ShapeHandle CreateShape(RigidBody* body);

    DT_SceneHandle m_scene;
    std::unordered_map<RigidBody*, DT_ObjectHandle> m_bodyToSolidObject;
    std::unordered_map<DT_ObjectHandle, RigidBody*> m_solidObjectToBody;
    std::unordered_map<ShapeType, DT_ShapeHandle> m_shapeHandles; 
};
