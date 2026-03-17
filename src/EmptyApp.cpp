#include "EmptyApp.h"
#include "Core/AssetPathHolder.h"
#include "Scene/SceneManager.h"
#include "GameScenes/EmptyGameScene.h"

void EmptyApp::BeginApplication()
{
    InitializeAppSystems();
    StartGame();
}

void EmptyApp::InitializeAppSystems()
{
    Core::AssetPathHolder::GetInstance().UpdateAssetFolderPath("Assets/");
}

void EmptyApp::StartGame()
{
    m_scene = GetSceneManager().CreateScene<App::GameScenes::EmptyGameScene, 100>();
    m_scene->InitializeScene();
    m_scene->Start();
}

void EmptyApp::UpdateApplication(const float deltaTime)
{
    m_scene->Update(deltaTime);
}

void EmptyApp::EndApplication()
{
    m_isRunning = false;
}


