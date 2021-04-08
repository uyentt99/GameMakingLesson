#include "GSMenu.h"
#include <iostream>
using namespace std;

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSMenu::GSMenu()
{

}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{
	std::string bgPic = ResourceManagers::GetInstance()->getBackGround();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(bgPic);

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);
	
	//play button
	texture = ResourceManagers::GetInstance()->GetTexture(BUTTON_PLAY);
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 350);
	button->SetSize(70, 65);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Play);
		});
	m_listButton.push_back(button);

	//Setting button
	texture = ResourceManagers::GetInstance()->GetTexture(BUTTON_SETTING);
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2+100, 350);
	button->SetSize(70, 65);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Setting);
		});
	m_listButton.push_back(button);


	//help button
	texture = ResourceManagers::GetInstance()->GetTexture(BUTTON_HELP);
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2-100, 350);
	button->SetSize(70, 65);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Help);
		});
	m_listButton.push_back(button);

	//exit button
	texture = ResourceManagers::GetInstance()->GetTexture(BUTTON_EXIT);
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth - 40, screenHeight - 40);;
	button->SetSize(70,65);
	button->SetOnClick([]() {
		exit(0);
		});
	m_listButton.push_back(button);

	//text game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Algerian Regular");
	m_Text_gameName = std::make_shared< Text>(shader, font, "JURA RUN", TEXT_COLOR::RED, 2.0);
	m_Text_gameName->Set2DPosition(Vector2(screenWidth / 2 - 110, 120));

	// character
	//shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	//texture = ResourceManagers::GetInstance()->GetTexture("Run");
	//m_character = std::make_shared<Animation2D>(model, shader, texture, 8, 0.1f);
	m_character = std::make_shared<Character>();
	m_character->Set2DPosition(screenWidth / 2, screenHeight/2-30);
	m_character->SetSize(160, 135);
	m_character->run();
	
}

void GSMenu::Exit()
{
}


void GSMenu::Pause()
{

}

void GSMenu::Resume()
{

}


void GSMenu::HandleEvents()
{

}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSMenu::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	m_character->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSMenu::Draw()
{
	m_BackGround->Draw();
	m_character->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_Text_gameName->Draw();
}
