#include "GameScenes/TestScene.h"
#include "Components/PolygonCollider2D.h"
#include "Components/Rigidbody2D.h"
#include "Components/Transform.h"
#include "Core/CoreSystems/InputSystem.h"
#include "GameObjects/BasicCircle.h"
#include "GameObjects/BasicSquare.h"
#include "GameObjects/BasicPolygon.h"
#include "GameObjects/EntityCountText.h"
#include "GameObjects/TimeStepText.h"

void App::GameScenes::TestScene::CreateGameObjects()
{
    m_sq1 = AddGameObject<SDLPhysicsApp::GameObjects::BasicSquare>();
    m_sq2 = AddGameObject<SDLPhysicsApp::GameObjects::BasicSquare>();
    m_sq3 = AddGameObject<SDLPhysicsApp::GameObjects::BasicSquare>();
    AddGameObject<SDLPhysicsApp::GameObjects::TimeStepText>();
    AddGameObject<SDLPhysicsApp::GameObjects::EntityCountText>();
}

void App::GameScenes::TestScene::Start()
{
    GameScene::Start();

    m_sq1->GetComponent<Components::Transform>()->Position = glm::vec2(-300.0f, 0.0f);
    m_sq2->GetComponent<Components::Transform>()->Position = glm::vec2( 300.0f, 0.0f);
    m_sq3->GetComponent<Components::Transform>()->Position = glm::vec2(0.0f, -500.0f);
    m_sq3->GetComponent<Components::Transform>()->Scale = glm::vec2(10000.0f, 100.0f);
    m_sq3->GetComponent<Components::Rigidbody2D>()->SetIsStatic(true);
    m_sq3->GetComponent<Components::PolygonCollider2D>()->SetBoxHalfExtents(
        glm::vec2(m_sq3->GetComponent<Components::Transform>()->Scale * 0.5f));
}

void App::GameScenes::TestScene::Update(const float deltaTime)
{
    GameScene::Update(deltaTime);

    if (Core::Input::InputSystem::GetInstance().IsKeyPressed(SDL_SCANCODE_1))
    {
        auto sq = AddGameObject<SDLPhysicsApp::GameObjects::BasicSquare>();
        sq->GetComponent<Components::Transform>()->Position = GetMouseWorldCoords();
    }
    if (Core::Input::InputSystem::GetInstance().IsKeyPressed(SDL_SCANCODE_2))
    {
        auto circle = AddGameObject<SDLPhysicsApp::GameObjects::BasicCircle>();
        circle->GetComponent<Components::Transform>()->Position = GetMouseWorldCoords();
    }
    if (Core::Input::InputSystem::GetInstance().IsKeyPressed(SDL_SCANCODE_3))
    {
        auto triangle = AddGameObject<SDLPhysicsApp::GameObjects::BasicPolygon>();
        triangle->m_NumberOfVertices = 3;
        auto transform = triangle->GetComponent<Components::Transform>();
        transform->Position = GetMouseWorldCoords();
    }
    if (Core::Input::InputSystem::GetInstance().IsKeyPressed(SDL_SCANCODE_4))
    {
        auto pentagon = AddGameObject<SDLPhysicsApp::GameObjects::BasicPolygon>();
        pentagon->m_NumberOfVertices = 5;
        auto transform = pentagon->GetComponent<Components::Transform>();
        transform->Position = GetMouseWorldCoords();
    }
    if (Core::Input::InputSystem::GetInstance().IsKeyPressed(SDL_SCANCODE_5))
    {
        auto hexagon = AddGameObject<SDLPhysicsApp::GameObjects::BasicPolygon>();
        hexagon->m_NumberOfVertices = 6;
        auto transform = hexagon->GetComponent<Components::Transform>();
        transform->Position = GetMouseWorldCoords();
    }
}