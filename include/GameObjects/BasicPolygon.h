#pragma once
#include "Scene/GameObject.h"

namespace SDLPhysicsApp::GameObjects
{
    class BasicPolygon : public Scene::GameObject
    {
    public:
        BasicPolygon() = default;
        ~BasicPolygon() override = default;

        void AddComponentsBeforeStartup() override;
        void Start() override;

    public:
        int m_NumberOfVertices = 3;
    };
}
