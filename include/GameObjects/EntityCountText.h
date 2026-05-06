#pragma once
#include "UI/UIText.h"


namespace SDLPhysicsApp::GameObjects
{
    class EntityCountText : public App::GameObjects::UIText
    {
    public:
        EntityCountText() = default;
        ~EntityCountText() override = default;

        void Start() override;
        void Update(const float deltaTime) override;
    };
}
