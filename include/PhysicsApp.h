#pragma once
#include "Core/GameScene.h"

namespace Core
{
    class GameScene;
}

class PhysicsApp : public Application
{
public:
    PhysicsApp() = default;
    ~PhysicsApp() override = default;

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
    static PhysicsApp app;
    return &app;
}
