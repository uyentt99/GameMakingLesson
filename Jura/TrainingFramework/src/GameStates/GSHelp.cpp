#include "GSHelp.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSHelp::GSHelp()
{

}


GSHelp::~GSHelp()
{
}



void GSHelp::Init()
{
	
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	
	//BackGround
	std::string bgPic = ResourceManagers::GetInstance()->getBackGround();
	auto texture = ResourceManagers::GetInstance()->GetTexture(bgPic);
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);


	texture = ResourceManagers::GetInstance()->GetTexture(BUTTON_BACK);
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
	std::shared_ptr<Text> text = std::make_shared< Text>(shader, font, "How to play?", TEXT_COLOR::RED, 1.5);
	text->Set2DPosition(Vector2(screenWidth / 2 - 110, 120));
	m_listText.push_back(text);

	font = ResourceManagers::GetInstance()->GetFont("arialbd");
	text = std::make_shared< Text>(shader, font, "Press any key to start, up to jump and down to slide", TEXT_COLOR::BLACK, 1.0);
	text->Set2DPosition(Vector2(screenWidth / 2-300, screenHeight / 2 + 90));
	m_listText.push_back(text);



	std::shared_ptr<Character> character = std::make_shared<Character>();
	character->Set2DPosition(screenWidth / 2-250, screenHeight / 2 - 30);
	character->SetSize(160, 135);
	character->run();
	m_listCharacter.push_back(character);


	character = std::make_shared<Character>();
	character->Set2DPosition(screenWidth / 2, screenHeight / 2 - 30);
	character->SetSize(160, 135);
	character->jump();
	m_listCharacter.push_back(character);

	character = std::make_shared<Character>();
	character->Set2DPosition(screenWidth / 2+250, screenHeight / 2 - 30);
	character->SetSize(160, 135);
	character->slide();
	m_listCharacter.push_back(character);
}

void GSHelp::Exit()
{
}


void GSHelp::Pause()
{

}

void GSHelp::Resume()
{

}


void GSHelp::HandleEvents()
{

}

void GSHelp::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSHelp::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSHelp::Update(float deltaTime)
{
	for (auto it : m_listCharacter)
	{
		it->Update(deltaTime);
	}
}

void GSHelp::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}

	for (auto it : m_listCharacter)
	{
		it->Draw();
	}
	
	for (auto it : m_listText)
	{
		it->Draw();
	}
}
