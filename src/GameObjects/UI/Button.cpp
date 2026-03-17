#include "../../../include/GameObjects/UI/Button.h"
#include "Components/Renderer2D.h"
#include "Components/Transform.h"
#include "Components/UITexture.h"

const inline std::string BLANK_IMAGE_FILEPATH = "images/img_blank.png";

void App::GameObjects::Button::AddComponentsBeforeStartup()
{
	AddComponent<Components::Transform>();
	AddComponent<Components::UITexture>();
	AddComponent<Components::Renderer2D>();
}

void App::GameObjects::Button::Start()
{
	auto transform = GetComponent<Components::Transform>();
	transform->LocalScale = glm::vec2(100.0f, 50.0f);

	auto renderer = GetComponent<Components::Renderer2D>();
	renderer->RenderTexture = GetSceneReference().GetResourceManager().TryLoadAndGetTexture(
		BLANK_IMAGE_FILEPATH);
	renderer->Color = SDL_FColor{0, 0, 0, 255};
}

void App::GameObjects::Button::SetOnClickFunction(std::function<void()> function)
{
	OnClickFunction = function;
}

void App::GameObjects::Button::SetBackGroundColor(SDL_FColor color)
{
	if (auto renderer = GetComponent<Components::Renderer2D>())
	{
		renderer->Color = color;
	}
}

void App::GameObjects::Button::OnSelect()
{
	SetBackGroundColor(m_onSelectBackgroundColor);
}

void App::GameObjects::Button::OnUnSelect()
{
	SetBackGroundColor(m_onUnSelectBackgroundColor);
}

void App::GameObjects::Button::OnClick()
{
	OnClickFunction();
}





