#include "GameObjects/BasicPolygon.h"
#include "Components/PolygonCollider2D.h"
#include "Components/Renderer2D.h"
#include "Components/Rigidbody2D.h"
#include "Components/Transform.h"
#include "Core/CoreSystems/ResourceManager.h"

const inline std::string POLYGON_TEXTURE_FILEPATH = "images/img_woodenBox.png";


void SDLPhysicsApp::GameObjects::BasicPolygon::AddComponentsBeforeStartup()
{
    AddComponent<Components::Transform>();
    AddComponent<Components::PolygonCollider2D>();
    AddComponent<Components::Rigidbody2D>();
    AddComponent<Components::Renderer2D>();
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


    auto renderer = GetComponent<Components::Renderer2D>();
    renderer->Color = SDL_FColor{173, 216, 230, 255};
    renderer->RenderTexture = GetSceneReference().GetResourceManager().TryLoadAndGetTexture(
    POLYGON_TEXTURE_FILEPATH);

    auto rigidbody = GetComponent<Components::Rigidbody2D>();
    rigidbody->SetMass(1000.0f);
    rigidbody->Restitution = 0.8f;

    DoDebug(m_name = "Basic Polygon");
}

