#include "GameObjects/StaticBox.h"
#include "Components/BoxCollider2D.h"
#include "Components/Transform.h"

void SDLPhysicsApp::GameObjects::StaticBox::AddComponentsBeforeStartup()
{
    AddComponent<Components::Transform>();
    AddComponent<Components::BoxCollider2D>();
}

void SDLPhysicsApp::GameObjects::StaticBox::Start()
{
    auto transform = GetComponent<Components::Transform>();
    transform->Position = glm::vec2(0.0f, -270.0f);
    transform->Scale = glm::vec2(900.0f, 50.0f);
    transform->Static = true;

    auto boxCollider2D = GetComponent<Components::BoxCollider2D>();
    boxCollider2D->SetHalfExtents(transform->Scale * 0.5f);

#ifdef _DEBUG
    m_name = "StaticBox";
#endif
}

