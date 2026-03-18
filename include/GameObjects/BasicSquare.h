#pragma once
#include "Scene/GameObject.h"

namespace SDLPhysicsApp::GameObjects
{
    class BasicSquare : public Scene::GameObject
    {
    public:
        BasicSquare() = default;
        ~BasicSquare() override = default;

        void AddComponentsBeforeStartup() override;
        void Start() override;
        void Update(const float deltaTime) override;
    };
}
