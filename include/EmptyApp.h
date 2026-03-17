#pragma once
#include "Core/GameScene.h"

namespace Core
{
    class GameScene;
}

class EmptyApp : public Application
{
public:
    EmptyApp() = default;
    ~EmptyApp() override = default;

    void BeginApplication() override;
    void UpdateApplication(float deltaTime) override;
    void EndApplication() override;

private:
    void InitializeAppSystems();
    void StartGame();

private:
    Core::GameScene* m_scene = nullptr;
};

inline Application* GetApplicationInstance()
{
    static EmptyApp app;
    return &app;
}
