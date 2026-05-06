#include "GameObjects/EntityCountText.h"
#include "Components/Transform.h"
#include "Components/UITexture.h"

void SDLPhysicsApp::GameObjects::EntityCountText::Start()
{
    App::GameObjects::UIText::Start();
    auto transform = GetComponent<Components::Transform>();
    transform->Position = glm::vec2(-836, 363);
    transform->Scale = glm::vec2(200.0f, 50.0f);
}

void SDLPhysicsApp::GameObjects::EntityCountText::Update(const float deltaTime)
{
    auto uiText = GetComponent<Components::UITexture>();
    uiText->SetFontText("Physics Entity Count: " +
        std::to_string(GetSceneReference().GetGameObjectCount() - 2),
        SDL_Color{ 255, 255, 255, 255 });
}

