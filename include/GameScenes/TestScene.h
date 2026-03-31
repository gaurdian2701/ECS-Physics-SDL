#pragma once
#include "Core/GameScene.h"

namespace SDLPhysicsApp::GameObjects
{
    class BasicSquare;
}

namespace App::GameScenes
{
    class TestScene : public Core::GameScene
    {
    public:
        explicit TestScene(int maxGameObjects) : GameScene(maxGameObjects) {}
        ~TestScene() override = default;

        void Start() override;
        void CreateGameObjects() override;
        void Update(const float deltaTime) override;

    private:
        SDLPhysicsApp::GameObjects::BasicSquare* m_sq1 = nullptr;
        SDLPhysicsApp::GameObjects::BasicSquare* m_sq2 = nullptr;
    };
}
