#include "GSPlay.h"
#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{

}


void GSPlay::Init()
{
	keyPressed = -1; 

	std::string bgPic = ResourceManagers::GetInstance()->getBackGround();
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(bgPic);

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround1 = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround1->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround1->SetSize(screenWidth, screenHeight);

	m_BackGround2 = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround2->Set2DPosition(screenWidth / 2+screenWidth, screenHeight / 2);
	m_BackGround2->SetSize(screenWidth, screenHeight);

	//back button
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
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	std::shared_ptr<Text> text = std::make_shared< Text>(shader, font, "score: 10", TEXT_COLOR::RED, 1.0);
	text->Set2DPosition(Vector2(screenWidth-300, 60));
	m_listText.push_back(text);

	std::string highScore = ResourceManagers::GetInstance()->getHighScore();
	font = ResourceManagers::GetInstance()->GetFont("arialbd");
	text = std::make_shared< Text>(shader, font, "High score: "+highScore, TEXT_COLOR::RED, 1.0);
	text->Set2DPosition(Vector2(screenWidth - 300, 30));
	m_listText.push_back(text);


	m_character = std::make_shared<Character>();
	m_character->Set2DPosition(100, 350);
	m_character->SetSize(160, 135);
	m_character->run();
}

void GSPlay::Exit()
{

}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{

}


void GSPlay::HandleEvents()
{

}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed) 
		keyPressed = key;
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}


void GSPlay::UpdateBackGround(float deltaTime) {
	positinBG = positinBG + 100.0f * deltaTime;
	m_BackGround1->Set2DPosition(screenWidth / 2-positinBG, screenHeight / 2);
	m_BackGround2->Set2DPosition(screenWidth / 2 + screenWidth-positinBG, screenHeight / 2);
	if (positinBG>=screenWidth){
		positinBG -= screenWidth;
	}
}

void GSPlay::Update(float deltaTime)
{
	UpdateBackGround(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}

	for (auto it : m_listText)
	{
		it->Update(deltaTime);
	}

	m_character->Update(deltaTime);

	if (keyPressed == KEY_UP) m_character->jump();
	if (keyPressed == KEY_RIGHT) m_character->run();
	if (keyPressed == KEY_DOWN) m_character->slide();
	keyPressed = -1;
}

void GSPlay::Draw()
{
	m_BackGround1->Draw();
	m_BackGround2->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}

	for (auto it : m_listText)
	{
		it->Draw();
	}
	m_character->Draw();
}

void GSPlay::SetNewPostionForBullet()
{
}