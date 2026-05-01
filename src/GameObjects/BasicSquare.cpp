#include "GameObjects/BasicSquare.h"
#include "Components/PolygonCollider2D.h"
#include "Components/ParticleEmitter.h"
#include "Components/Renderer2D.h"
#include "Components/Rigidbody2D.h"
#include "Components/Transform.h"

const inline std::string SQUARE_TEXTURE_FILEPATH = "images/img_woodenBox.png";

void SDLPhysicsApp::GameObjects::BasicSquare::AddComponentsBeforeStartup()
{
    AddComponent<Components::Transform>();
    AddComponent<Components::Renderer2D>();
    AddComponent<Components::PolygonCollider2D>();
    AddComponent<Components::Rigidbody2D>();
}

void SDLPhysicsApp::GameObjects::BasicSquare::Start()
{
    auto transform = GetComponent<Components::Transform>();
    transform->Scale = glm::vec2(100.0f);

    auto box = GetComponent<Components::PolygonCollider2D>();
    box->InitializeBox(transform->Position,
        glm::vec2(transform->Scale * 0.5f),
        0.0f);

    auto renderer = GetComponent<Components::Renderer2D>();
    renderer->RenderTexture = GetSceneReference().GetResourceManager().TryLoadAndGetTexture(
        SQUARE_TEXTURE_FILEPATH);

    auto rigidbody = GetComponent<Components::Rigidbody2D>();
    rigidbody->SetMass(100.0f);
    rigidbody->Restitution = 0.8f;

    DoDebug(m_name = "Basic Square");
}

void SDLPhysicsApp::GameObjects::BasicSquare::Update(const float deltaTime)
{
}


