#pragma once
#include "Core/GameScene.h"

namespace App::GameScenes
{
    class EmptyGameScene : public Core::GameScene
    {
    public:
        explicit EmptyGameScene(int maxGameObjects) : GameScene(maxGameObjects) {}
        ~EmptyGameScene() override = default;

        void CreateGameObjects() override;

    protected:
        void InitializeGameObjectReferences() override;
    };
}
