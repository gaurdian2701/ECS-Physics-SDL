#include "GameObjects/BasicCircle.h"
#include "Components/PolygonCollider2D.h"
#include "Components/CircleCollider2D.h"
#include "Components/Renderer2D.h"
#include "Components/Rigidbody2D.h"
#include "Components/Transform.h"


const inline std::string CIRCLE_TEXTURE_FILEPATH = "images/img_circle.png";

void SDLPhysicsApp::GameObjects::BasicCircle::AddComponentsBeforeStartup()
{
    AddComponent<Components::Transform>();
    AddComponent<Components::Renderer2D>();
    AddComponent<Components::CircleCollider2D>();
    AddComponent<Components::Rigidbody2D>();
}

void SDLPhysicsApp::GameObjects::BasicCircle::Start()
{
    auto transform = GetComponent<Components::Transform>();
    transform->Scale = glm::vec2(100.0f);

    auto renderer = GetComponent<Components::Renderer2D>();
    renderer->Color = SDL_FColor{173, 216, 230, 255};
    renderer->RenderTexture = GetSceneReference().GetResourceManager().TryLoadAndGetTexture(
    CIRCLE_TEXTURE_FILEPATH);

    auto circleCollider = GetComponent<Components::CircleCollider2D>();
    circleCollider->MatchScaleWithTransform = false;
    circleCollider->Initialize(transform->Position, transform->Scale.x * 0.5f);

    DoDebug(m_name = "Circle");
}

