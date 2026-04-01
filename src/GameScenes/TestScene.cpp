#include "GameScenes/TestScene.h"

#include "Components/Rigidbody2D.h"
#include "Components/Transform.h"
#include "GameObjects/BasicCircle.h"
#include "GameObjects/BasicSquare.h"
#include "GameObjects/StaticBox.h"

void App::GameScenes::TestScene::CreateGameObjects()
{
    m_sq1 = AddGameObject<SDLPhysicsApp::GameObjects::BasicSquare>();
    m_sq2 = AddGameObject<SDLPhysicsApp::GameObjects::BasicSquare>();
    // AddGameObject<SDLPhysicsApp::GameObjects::BasicCircle>();
    // AddGameObject<SDLPhysicsApp::GameObjects::BasicCircle>();
    AddGameObject<SDLPhysicsApp::GameObjects::StaticBox>();
}

void App::GameScenes::TestScene::Start()
{
    m_sq1->GetComponent<Components::Transform>()->Position = glm::vec2(-450.0f, 0.0f);
    m_sq2->GetComponent<Components::Transform>()->Position = glm::vec2( 450.0f, 0.0f);

    auto rb1 = m_sq1->GetComponent<Components::Rigidbody2D>();
    auto rb2 = m_sq2->GetComponent<Components::Rigidbody2D>();

    rb1->LinearVelocity = glm::vec2(100.0f, 0.0f);
    rb2->LinearVelocity = glm::vec2(-100.0f, 0.0f);
}

void App::GameScenes::TestScene::Update(const float deltaTime)
{
    GameScene::Update(deltaTime);
}