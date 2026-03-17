#pragma once
#include "Scene/GameObject.h"

namespace EmptyApp::GameObjects
{
    class ParticleEmitterGameObject : public Scene::GameObject
    {
    public:
        ParticleEmitterGameObject() = default;
        ~ParticleEmitterGameObject() override = default;

        void AddComponentsBeforeStartup() override;
        void Start() override;
        void Update(const float deltaTime) override;
    };
}
