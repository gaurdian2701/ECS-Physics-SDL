#include "GameObjects/BasicPolygon.h"
#include "Components/PolygonCollider2D.h"
#include "Components/Renderer2D.h"
#include "Components/Rigidbody2D.h"
#include "Components/Transform.h"

const inline std::string TRIANGLE_TEXTURE_FILEPATH = "images/img_blank.png";


void SDLPhysicsApp::GameObjects::BasicPolygon::AddComponentsBeforeStartup()
{
    AddComponent<Components::Transform>();
    AddComponent<Components::PolygonCollider2D>();
    AddComponent<Components::Rigidbody2D>();
}

void SDLPhysicsApp::GameObjects::BasicPolygon::Start()
{
    auto transform = GetComponent<Components::Transform>();
    transform->Scale = glm::vec2(100.0f);

    auto collider = GetComponent<Components::PolygonCollider2D>();
    collider->InitializePolygon(transform->Position,
        m_NumberOfVertices,
        glm::length(transform->Scale) * 0.5f,
        0.0f);

    auto rigidbody = GetComponent<Components::Rigidbody2D>();
    rigidbody->SetMass(1000.0f);
    rigidbody->Restitution = 0.8f;

    DoDebug(m_name = "Basic Polygon");
}

