#include "GameObjects/TimeStepText.h"
#include "Components/Transform.h"
#include "Components/UITexture.h"
#include "Core/ECS/Systems/PhysicsSystem.h"

void SDLPhysicsApp::GameObjects::TimeStepText::Start()
{
    App::GameObjects::UIText::Start();
    m_physicsSystem = Core::ECS::ECSManager::GetInstance().GetSystem<Core::ECS::Systems::PhysicsSystem>();
    auto transform = GetComponent<Components::Transform>();
    transform->Position = glm::vec2(-836, 433);
    transform->Scale = glm::vec2(200.0f, 50.0f);
}

void SDLPhysicsApp::GameObjects::TimeStepText::Update(const float deltaTime)
{
    auto uiText = GetComponent<Components::UITexture>();
    uiText->SetFontText(m_physicsSystem->m_broadPhaseUsedText + " " +
        std::to_string(m_physicsSystem->m_TimeTakenForPhysicsStep), SDL_Color{ 255, 255, 255, 255 });
}

