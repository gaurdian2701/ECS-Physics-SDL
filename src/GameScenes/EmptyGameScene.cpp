#include "GameScenes/EmptyGameScene.h"

#include "GameObjects/ParticleEmitterGameObject.h"

void App::GameScenes::EmptyGameScene::CreateGameObjects()
{
    AddGameObject<EmptyApp::GameObjects::ParticleEmitterGameObject>();
}

void App::GameScenes::EmptyGameScene::InitializeGameObjectReferences()
{
}
