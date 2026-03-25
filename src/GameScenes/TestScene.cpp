#include "GameScenes/TestScene.h"

#include "GameObjects/BasicCircle.h"
#include "GameObjects/BasicSquare.h"
#include "GameObjects/StaticBox.h"

void App::GameScenes::TestScene::CreateGameObjects()
{
    AddGameObject<SDLPhysicsApp::GameObjects::BasicSquare>();
    AddGameObject<SDLPhysicsApp::GameObjects::BasicSquare>();
    AddGameObject<SDLPhysicsApp::GameObjects::BasicSquare>();
    AddGameObject<SDLPhysicsApp::GameObjects::BasicCircle>();
    AddGameObject<SDLPhysicsApp::GameObjects::BasicCircle>();
    AddGameObject<SDLPhysicsApp::GameObjects::StaticBox>();
}

void App::GameScenes::TestScene::InitializeGameObjectReferences()
{
}
