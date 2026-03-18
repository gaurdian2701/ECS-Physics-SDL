#include "GameObjects/BasicCircle.h"
#include "Components/AABB2D.h"
#include "Components/CircleCollider2D.h"
#include "Components/Renderer2D.h"
#include "Components/Transform.h"


const inline std::string CIRCLE_TEXTURE_FILEPATH = "images/img_blankCircle.png";

void SDLPhysicsApp::GameObjects::BasicCircle::AddComponentsBeforeStartup()
{
    AddComponent<Components::Transform>();
    AddComponent<Components::Renderer2D>();
    AddComponent<Components::CircleCollider2D>();
}

void SDLPhysicsApp::GameObjects::BasicCircle::Start()
{
    auto transform = GetComponent<Components::Transform>();
    transform->LocalPosition = glm::vec2(20.0f, 0.0f);
    transform->LocalScale = glm::vec2(25.0f);

    auto renderer = GetComponent<Components::Renderer2D>();
    renderer->Color = SDL_FColor{50, 130, 240, 255};
    renderer->RenderTexture = GetSceneReference().GetResourceManager().TryLoadAndGetTexture(
    CIRCLE_TEXTURE_FILEPATH);

    auto circleCollider = GetComponent<Components::CircleCollider2D>();
    circleCollider->Radius = transform->LocalScale.x * 0.6f;

#ifdef _DEBUG
    m_name = "Circle";
#endif
}

