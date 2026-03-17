#include "GameObjects/ParticleEmitterGameObject.h"
#include "Components/ParticleEmitter.h"
#include "Components/Renderer2D.h"
#include "Components/Transform.h"

const inline std::string PARTICLE_TEXTURE_FILEPATH = "images/img_blank.png";

void EmptyApp::GameObjects::ParticleEmitterGameObject::AddComponentsBeforeStartup()
{
    AddComponent<Components::Transform>();
    AddComponent<Components::Renderer2D>();
    AddComponent<Components::ParticleEmitter>();
}

void EmptyApp::GameObjects::ParticleEmitterGameObject::Start()
{
    auto transform = GetComponent<Components::Transform>();
    transform->LocalScale = glm::vec2(25.0f);

    auto renderer = GetComponent<Components::Renderer2D>();
    renderer->RenderTexture = GetSceneReference().GetResourceManager().TryLoadAndGetTexture(
        PARTICLE_TEXTURE_FILEPATH);
    renderer->Color = SDL_FColor{50, 130, 240, 255};

    auto particleEmitter = GetComponent<Components::ParticleEmitter>();
    particleEmitter->InitializeEmitter(10,
        std::forward<glm::vec2>(glm::vec2(0.0f, -20.0f)),
        std::forward<glm::vec2>(glm::vec2(0.0f)),
        3.0f,
        20.0f,
        0.1f,
        5.0f);
    particleEmitter->UseOwnerDirection = true;
    particleEmitter->RenderTexture = GetSceneReference().GetResourceManager().GetTexture(
        PARTICLE_TEXTURE_FILEPATH);

#ifdef _DEBUG
    m_name = "Particle Emitter";
#endif
}

void EmptyApp::GameObjects::ParticleEmitterGameObject::Update(const float deltaTime)
{
    auto transform = GetComponent<Components::Transform>();
    transform->LocalPosition += transform->Up * deltaTime;
}


