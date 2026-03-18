#include "PhysicsApp.h"
#include "Core/AssetPathHolder.h"
#include "Scene/SceneManager.h"
#include "GameScenes/TestScene.h"

void PhysicsApp::BeginApplication()
{
    InitializeAppSystems();
    StartGame();
}

void PhysicsApp::InitializeAppSystems()
{
    Core::AssetPathHolder::GetInstance().UpdateAssetFolderPath("Assets/");
}

void PhysicsApp::StartGame()
{
    m_scene = GetSceneManager().CreateScene<App::GameScenes::TestScene, 100>();
    m_scene->InitializeScene();
    m_scene->Start();
}

void PhysicsApp::UpdateApplication(const float deltaTime)
{
    m_scene->Update(deltaTime);
}

void PhysicsApp::EndApplication()
{
    m_isRunning = false;
}


