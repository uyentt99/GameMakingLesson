#pragma once
#include "Sprite2D.h"
class Animation2D : public Sprite2D {
protected:
	int m_NumFrame;
	float m_FrameTime;
	int m_CurrentFrame;
	float m_CurrentTime;
public:
	Animation2D(int numFrame, float frameTime);
	Animation2D(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture, int m_Numframe, float m_Frametime);
	~Animation2D();

	void		Draw() override;
	void		Update(GLfloat deltatime) override;
};