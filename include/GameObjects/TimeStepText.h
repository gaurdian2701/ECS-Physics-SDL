#pragma once
#include "UI/UIText.h"

namespace Core::ECS::Systems
{
    class PhysicsSystem;
}

namespace SDLPhysicsApp::GameObjects
{
    class TimeStepText : public App::GameObjects::UIText
    {
        public:
            TimeStepText() = default;
            ~TimeStepText() override = default;

        void Start() override;
        void Update(const float deltaTime) override;

    private:
        Core::ECS::Systems::PhysicsSystem* m_physicsSystem = nullptr;
    };
}
