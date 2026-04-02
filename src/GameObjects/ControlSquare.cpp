#include "GameObjects/ControlSquare.h"

#include "Components/BoxCollider2D.h"
#include "Components/Renderer2D.h"
#include "Components/Rigidbody2D.h"
#include "Components/Transform.h"
#include "Core/CoreSystems/InputSystem.h"

void SDLPhysicsApp::GameObjects::ControlSquare::AddComponentsBeforeStartup()
{
    AddComponent<Components::Transform>();
    AddComponent<Components::Renderer2D>();
    AddComponent<Components::BoxCollider2D>();
    AddComponent<Components::Rigidbody2D>();
}

void SDLPhysicsApp::GameObjects::ControlSquare::Start()
{
    auto transform = GetComponent<Components::Transform>();
    transform->Position = glm::vec2(0.0f, 400.0f);
    transform->Scale = glm::vec2(60.0f);

    auto boxCollider = GetComponent<Components::BoxCollider2D>();
    boxCollider->Initialize(transform->Position,
        transform->Scale * 0.5f,
        transform->Rotation);
}

void SDLPhysicsApp::GameObjects::ControlSquare::Update(const float deltaTime)
{
    auto rb = GetComponent<Components::Rigidbody2D>();

    if (Core::Input::InputSystem::GetInstance().CheckForKeyPress(SDL_SCANCODE_UP))
    {
        rb->AddForce(glm::vec2(0.0f, m_accelerationForce));
    }
    if (Core::Input::InputSystem::GetInstance().CheckForKeyPress(SDL_SCANCODE_DOWN))
    {
        rb->AddForce(glm::vec2(0.0f, -m_accelerationForce));
    }
    if (Core::Input::InputSystem::GetInstance().CheckForKeyPress(SDL_SCANCODE_LEFT))
    {
        rb->AddForce(glm::vec2(-m_accelerationForce, 0.0f));
    }
    if (Core::Input::InputSystem::GetInstance().CheckForKeyPress(SDL_SCANCODE_RIGHT))
    {
        rb->AddForce(glm::vec2( m_accelerationForce, 0.0f));
    }
}


