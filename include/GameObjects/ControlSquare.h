#pragma once
#include "Scene/GameObject.h"

namespace SDLPhysicsApp::GameObjects
{
    class ControlSquare : public Scene::GameObject
    {
    public:
        ControlSquare() = default;
        ~ControlSquare() override  = default;

        void AddComponentsBeforeStartup() override;
        void Start() override;
        void Update(const float deltaTime) override;

    private:
        float m_accelerationForce = 1.0f;
    };
}
