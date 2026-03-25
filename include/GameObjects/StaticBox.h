#pragma once
#include "Scene/GameObject.h"

namespace SDLPhysicsApp::GameObjects
{
    class StaticBox : public Scene::GameObject
    {
    public:
        StaticBox() = default;
        ~StaticBox() override = default;

        void AddComponentsBeforeStartup() override;
        void Start() override;
    };
}
