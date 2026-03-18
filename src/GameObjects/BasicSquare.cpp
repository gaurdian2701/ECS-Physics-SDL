#include "GameObjects/BasicSquare.h"
#include "Components/AABB2D.h"
#include "Components/ParticleEmitter.h"
#include "Components/Renderer2D.h"
#include "Components/Transform.h"

const inline std::string SQUARE_TEXTURE_FILEPATH = "images/img_blankSquare.png";

void SDLPhysicsApp::GameObjects::BasicSquare::AddComponentsBeforeStartup()
{
    AddComponent<Components::Transform>();
    AddComponent<Components::Renderer2D>();
    AddComponent<Components::AABB2D>();
}

void SDLPhysicsApp::GameObjects::BasicSquare::Start()
{
    auto transform = GetComponent<Components::Transform>();
    transform->LocalScale = glm::vec2(25.0f);

    auto aabb = GetComponent<Components::AABB2D>();
    aabb->HalfExtents = glm::vec2(transform->LocalScale * 0.6f);

    auto renderer = GetComponent<Components::Renderer2D>();
    renderer->Color = SDL_FColor{50, 130, 240, 255};
    renderer->RenderTexture = GetSceneReference().GetResourceManager().TryLoadAndGetTexture(
        SQUARE_TEXTURE_FILEPATH);

#ifdef _DEBUG
    m_name = "Square";
#endif
}

void SDLPhysicsApp::GameObjects::BasicSquare::Update(const float deltaTime)
{

}


