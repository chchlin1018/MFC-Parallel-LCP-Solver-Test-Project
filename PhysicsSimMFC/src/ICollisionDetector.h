#pragma once

#include "Contact.h"
#include "RigidBody.h"
#include <vector>

class ICollisionDetector {
public:
    virtual ~ICollisionDetector() = default;

    virtual void AddRigidBody(RigidBody* body) = 0;
    virtual void RemoveRigidBody(RigidBody* body) = 0;
    virtual void DetectCollisions(std::vector<Contact>& contacts) = 0;
    virtual void UpdateRigidBodyTransform(RigidBody* body) = 0;
};
