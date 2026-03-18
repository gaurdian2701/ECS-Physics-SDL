#pragma once
#include "Core/GameScene.h"

namespace App::GameScenes
{
    class TestScene : public Core::GameScene
    {
    public:
        explicit TestScene(int maxGameObjects) : GameScene(maxGameObjects) {}
        ~TestScene() override = default;

        void CreateGameObjects() override;

    protected:
        void InitializeGameObjectReferences() override;
    };
}
