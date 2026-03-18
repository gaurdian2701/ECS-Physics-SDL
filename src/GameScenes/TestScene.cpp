#include "GameScenes/TestScene.h"

#include "GameObjects/BasicCircle.h"
#include "GameObjects/BasicSquare.h"

void App::GameScenes::TestScene::CreateGameObjects()
{
    AddGameObject<SDLPhysicsApp::GameObjects::BasicSquare>();
    AddGameObject<SDLPhysicsApp::GameObjects::BasicSquare>();
    AddGameObject<SDLPhysicsApp::GameObjects::BasicCircle>();
}

void App::GameScenes::TestScene::InitializeGameObjectReferences()
{
}
