#pragma once
#include "gamestatebase.h"
#include "GameButton.h"

class GSHelp :
	public GameStateBase
{
public:
	GSHelp();
	~GSHelp();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);
	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();

private:
	std::shared_ptr<Sprite2D> m_BackGround;
	std::list<std::shared_ptr<Character>> m_listCharacter;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<Text>>  m_listText;

};

