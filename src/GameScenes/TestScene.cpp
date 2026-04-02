#include "GameScenes/TestScene.h"
#include "Components/Rigidbody2D.h"
#include "Components/Transform.h"
#include "GameObjects/BasicCircle.h"
#include "GameObjects/BasicSquare.h"
#include "GameObjects/ControlSquare.h"

void App::GameScenes::TestScene::CreateGameObjects()
{
    m_sq1 = AddGameObject<SDLPhysicsApp::GameObjects::BasicSquare>();
    m_sq2 = AddGameObject<SDLPhysicsApp::GameObjects::BasicSquare>();
    m_sq3 = AddGameObject<SDLPhysicsApp::GameObjects::BasicSquare>();
    AddGameObject<SDLPhysicsApp::GameObjects::ControlSquare>();
    // AddGameObject<SDLPhysicsApp::GameObjects::BasicCircle>();
    // AddGameObject<SDLPhysicsApp::GameObjects::BasicCircle>();
}

void App::GameScenes::TestScene::Start()
{
    m_sq1->GetComponent<Components::Transform>()->Position = glm::vec2(-300.0f, 0.0f);
    m_sq2->GetComponent<Components::Transform>()->Position = glm::vec2( 300.0f, 0.0f);
    m_sq3->GetComponent<Components::Transform>()->Position = glm::vec2(0.0f, -300.0f);
    m_sq3->GetComponent<Components::Rigidbody2D>()->SetIsStatic(true);

    auto rb1 = m_sq1->GetComponent<Components::Rigidbody2D>();
    auto rb2 = m_sq2->GetComponent<Components::Rigidbody2D>();
    auto rb3 = m_sq3->GetComponent<Components::Rigidbody2D>();
}

void App::GameScenes::TestScene::Update(const float deltaTime)
{
    GameScene::Update(deltaTime);
}