#pragma once
#include "Scene/GameObject.h"

namespace SDLPhysicsApp::GameObjects
{
    class BasicCircle : public Scene::GameObject
    {
    public:
        BasicCircle() = default;
        ~BasicCircle() override = default;

        void AddComponentsBeforeStartup() override;
        void Start() override;
    };
}
