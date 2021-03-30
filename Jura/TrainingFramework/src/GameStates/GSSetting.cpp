#include "GSSetting.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSSetting::GSSetting()
{

}


GSSetting::~GSSetting()
{
}



void GSSetting::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");

	auto texture = ResourceManagers::GetInstance()->GetTexture("buttonB");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(20, 20);
	button->SetSize(42, 34);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		//GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		});
	m_listButton.push_back(button);


	//text game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Algerian Regular");
	m_Text_gameName = std::make_shared< Text>(shader, font, "Setting", TEXT_COLOR::RED, 1.5);
	m_Text_gameName->Set2DPosition(Vector2(screenWidth / 2 - 70, 100));

}

void GSSetting::Exit()
{
}


void GSSetting::Pause()
{

}

void GSSetting::Resume()
{

}


void GSSetting::HandleEvents()
{

}

void GSSetting::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSSetting::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSSetting::Update(float deltaTime)
{
}

void GSSetting::Draw()
{
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_Text_gameName->Draw();
}
