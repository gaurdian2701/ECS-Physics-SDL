#include "GameObjects/BasicSquare.h"
#include "Components/BoxCollider2D.h"
#include "Components/ParticleEmitter.h"
#include "Components/Renderer2D.h"
#include "Components/Transform.h"

const inline std::string SQUARE_TEXTURE_FILEPATH = "images/img_blankSquare.png";

void SDLPhysicsApp::GameObjects::BasicSquare::AddComponentsBeforeStartup()
{
    AddComponent<Components::Transform>();
    AddComponent<Components::Renderer2D>();
    AddComponent<Components::BoxCollider2D>();
}

void SDLPhysicsApp::GameObjects::BasicSquare::Start()
{
    auto transform = GetComponent<Components::Transform>();
    transform->Scale = glm::vec2(25.0f);
    transform->Rotation = 3.0f;

    auto box = GetComponent<Components::BoxCollider2D>();
    box->Initialize(transform->Position,
        glm::vec2(transform->Scale * 0.6f),
        0.0f);


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


