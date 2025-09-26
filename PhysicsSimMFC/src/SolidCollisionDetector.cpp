#include "SolidCollisionDetector.h"
#include "RigidBody.h"
#include <iostream>

SolidCollisionDetector::SolidCollisionDetector() {
    m_scene = DtCreateScene();
}

SolidCollisionDetector::~SolidCollisionDetector() {
    for (auto const& [key, val] : m_shapeHandles) {
        DtDeleteShape(val);
    }
    DtDeleteScene(m_scene);
}

void SolidCollisionDetector::AddRigidBody(RigidBody* body) {
    DT_ShapeHandle shape = CreateShape(body);
    DT_ObjectHandle object = DtCreateObject(body, shape);
    DtAddObject(m_scene, object);
    m_bodyToSolidObject[body] = object;
    m_solidObjectToBody[object] = body;
}

void SolidCollisionDetector::RemoveRigidBody(RigidBody* body) {
    DT_ObjectHandle object = m_bodyToSolidObject[body];
    DtRemoveObject(m_scene, object);
    DtDestroyObject(object);
    m_bodyToSolidObject.erase(body);
    m_solidObjectToBody.erase(object);
}

void SolidCollisionDetector::DetectCollisions(std::vector<Contact>& contacts) {
    DtUpdate(m_scene);
    DtSelect(m_scene, DT_ALL_OBJECTS, DT_ALL_OBJECTS, DT_SIMPLE_RESPONSE);
    
    DT_CollData collData;
    for (int i = 0; i < DtGetNumPairs(m_scene); ++i) {
        DT_ObjectHandle obj1 = DtGetPair(m_scene, i, 0);
        DT_ObjectHandle obj2 = DtGetPair(m_scene, i, 1);

        if (DtGetCollData(obj1, obj2, &collData)) {
            Contact contact;
            contact.body1 = (RigidBody*)DtGetClientData(obj1);
            contact.body2 = (RigidBody*)DtGetClientData(obj2);
            contact.point1 = Eigen::Vector3d(collData.point1[0], collData.point1[1], collData.point1[2]);
            contact.point2 = Eigen::Vector3d(collData.point2[0], collData.point2[1], collData.point2[2]);
            contact.normal = Eigen::Vector3d(collData.normal[0], collData.normal[1], collData.normal[2]).normalized();
            contact.penetration = (contact.point2 - contact.point1).norm();
            contacts.push_back(contact);
        }
    }
}

void SolidCollisionDetector::UpdateRigidBodyTransform(RigidBody* body) {
    DT_ObjectHandle object = m_bodyToSolidObject[body];
    Eigen::Matrix4d transform = body->GetTransform();
    DtSetMatrixd(object, transform.data());
}

DT_ShapeHandle SolidCollisionDetector::CreateShape(RigidBody* body) {
    ShapeType type = body->GetShapeType();
    if (m_shapeHandles.count(type)) {
        return m_shapeHandles[type];
    }

    DT_ShapeHandle shape = nullptr;
    switch (type) {
        case ShapeType::Box: {
            Eigen::Vector3d halfExtents = body->GetHalfExtents();
            shape = DtNewBox(halfExtents.x(), halfExtents.y(), halfExtents.z());
            break;
        }
        case ShapeType::Sphere: {
            double radius = body->GetRadius();
            shape = DtNewSphere(radius);
            break;
        }
        // ... (add other shapes here)
    }
    m_shapeHandles[type] = shape;
    return shape;
}

