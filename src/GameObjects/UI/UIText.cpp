#include "GameObjects/UI/UIText.h"
#include "Components/Transform.h"
#include "Components/UITexture.h"

const inline std::string TEXT_FONT_PATH = "fonts/font_Arcade.ttf";

void App::GameObjects::UIText::AddComponentsBeforeStartup()
{
	AddComponent<Components::Transform>();
	AddComponent<Components::UITexture>();
}

void App::GameObjects::UIText::Start()
{
	auto transform = GetComponent<Components::Transform>();
	transform->Scale = glm::vec2(100.0f, 50.0f);

	auto uiTexture = GetComponent<Components::UITexture>();
	uiTexture->TextFont = GetSceneReference().GetResourceManager().TryLoadAndGetFont(
		TEXT_FONT_PATH, 24);

#ifdef _DEBUG
	m_name = "UI Text";
#endif
}

void App::GameObjects::UIText::SetFont(const char *pathToFont, float fontSize)
{
	if (auto uiTexture = GetComponent<Components::UITexture>())
	{
		uiTexture->TextFont = GetSceneReference().GetResourceManager().TryLoadAndGetFont(
			pathToFont, fontSize);
	}
}

void App::GameObjects::UIText::SetText(const std::string &text)
{
	if (auto uiTexture = GetComponent<Components::UITexture>())
	{
		uiTexture->SetFontText(text, std::forward<SDL_Color>(m_color));
	}
}
