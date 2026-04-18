#include "GameObjects/ControlSquare.h"

#include "Components/PolygonCollider2D.h"
#include "Components/Renderer2D.h"
#include "Components/Rigidbody2D.h"
#include "Components/Transform.h"
#include "Core/CoreSystems/InputSystem.h"
#include "GameObjects/BasicCircle.h"
#include "GameObjects/BasicSquare.h"

void SDLPhysicsApp::GameObjects::ControlSquare::AddComponentsBeforeStartup()
{
    AddComponent<Components::Transform>();
    AddComponent<Components::Renderer2D>();
    AddComponent<Components::PolygonCollider2D>();
    AddComponent<Components::Rigidbody2D>();
}

void SDLPhysicsApp::GameObjects::ControlSquare::Start()
{
    auto transform = GetComponent<Components::Transform>();
    transform->Position = glm::vec2(0.0f, 400.0f);
    transform->Scale = glm::vec2(60.0f);

    auto polygonCollider = GetComponent<Components::PolygonCollider2D>();
    polygonCollider->InitializeBox(transform->Position,
        transform->Scale * 0.5f,
        transform->Rotation);

    auto rb = GetComponent<Components::Rigidbody2D>();
    rb->SetIsStatic(true);
}

void SDLPhysicsApp::GameObjects::ControlSquare::Update(const float deltaTime)
{
    auto transform = GetComponent<Components::Transform>();

    if (Core::Input::InputSystem::GetInstance().IsKeyPressed(SDL_SCANCODE_UP))
    {
        transform->Position += glm::vec2(0.0f, m_accelerationForce) * deltaTime;
    }
    if (Core::Input::InputSystem::GetInstance().IsKeyPressed(SDL_SCANCODE_DOWN))
    {
        transform->Position += glm::vec2(0.0f, -m_accelerationForce) * deltaTime;
    }
    if (Core::Input::InputSystem::GetInstance().IsKeyPressed(SDL_SCANCODE_LEFT))
    {
        transform->Position += glm::vec2(-m_accelerationForce, 0.0f) * deltaTime;
    }
    if (Core::Input::InputSystem::GetInstance().IsKeyPressed(SDL_SCANCODE_RIGHT))
    {
        transform->Position += glm::vec2(m_accelerationForce, 0.0f) * deltaTime;
    }
}


