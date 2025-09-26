#pragma once

#include "RigidBody.h"
#include "ICollisionDetector.h"
#include "SolidCollisionDetector.h"
#include "ContactSolver.h"
#include <vector>
#include <memory>

class PhysicsWorld {
public:
    PhysicsWorld() {
        m_collisionDetector = std::make_unique<SolidCollisionDetector>();
        m_contactSolver = std::make_unique<ContactSolver>();
    }

    void AddBody(RigidBody* body) {
        m_bodies.push_back(body);
        m_collisionDetector->AddRigidBody(body);
    }

    void Step(float dt) {
        for (auto* body : m_bodies) {
            body->ApplyGravity();
            body->Integrate(dt);
            m_collisionDetector->UpdateRigidBodyTransform(body);
        }

        std::vector<Contact> contacts;
        m_collisionDetector->DetectCollisions(contacts);

        if (!contacts.empty()) {
            m_contactSolver->Solve(contacts, dt);
        }
    }

    const std::vector<RigidBody*>& GetBodies() const { return m_bodies; }

private:
    std::vector<RigidBody*> m_bodies;
    std::unique_ptr<ICollisionDetector> m_collisionDetector;
    std::unique_ptr<ContactSolver> m_contactSolver;
};
