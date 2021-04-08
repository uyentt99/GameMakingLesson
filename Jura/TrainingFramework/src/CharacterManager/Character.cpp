#include "Character.h"
#include "State.h"
#include "Running.h"
#include "Idle.h"

extern GLint screenWidth;
extern GLint screenHeight;

Character::Character():Animation2D(10,0.07f){
	m_pModel = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	m_pShader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_pCamera = nullptr;
	m_pTexture = ResourceManagers::GetInstance()->GetTexture("Idle");

	m_Vec3Position = Vector3(0, 0, 0);
	m_iHeight = 50;
	m_iWidth = 100;
	m_Vec3Scale = Vector3((float)m_iWidth / screenWidth, (float)m_iHeight / screenHeight, 1);

	current = new Idle();
}

void Character::setCurrent(State* s){
    current = s;
}

void Character::run(){
    current->run(this);
}

void Character::jump(){
    current->jump(this);
}

void Character::dead(){
    current->dead(this);
};

void Character::idle() {
    current->idle(this);
};

void Character::slide() {
    current->slide(this);
};

void Character::setTexture(std::string picName, int numFrame) {
	m_pTexture = ResourceManagers::GetInstance()->GetTexture(picName);
	m_NumFrame = numFrame;
	m_CurrentFrame = 0;
}

void Character::Update(float deltaTime) {
	current->update(this, deltaTime);
	//printf("Success");
}


void Character::UpdateStop(float deltaTime) {
	m_CurrentTime += deltaTime;
	if (m_CurrentFrame<m_NumFrame && m_CurrentTime >= m_FrameTime) {
		m_CurrentFrame++;
		//printf("%d",m_currentFrames);
		m_CurrentTime = m_CurrentTime - m_FrameTime;
	}
}
void Character::UpdateBackRun(float deltaTime) {
	m_CurrentTime += deltaTime;
	if (m_CurrentTime >= m_FrameTime) {
		m_CurrentFrame++;
		//printf("%d",m_currentFrames);
		if (m_CurrentFrame >= m_NumFrame) {
			run();
		}
		m_CurrentTime = m_CurrentTime - m_FrameTime;
	}
}

void Character::UpdateLoop(float deltaTime) {
	m_CurrentTime += deltaTime;
	if (m_CurrentTime >= m_FrameTime) {
		m_CurrentFrame++;
		//printf("%d",m_currentFrames);
		if (m_CurrentFrame >= m_NumFrame) {
			m_CurrentFrame = 0;
		}
		m_CurrentTime = m_CurrentTime - m_FrameTime;
	}
}
