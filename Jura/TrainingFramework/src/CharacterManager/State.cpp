#include "State.h"
#include "Running.h"
#include "Dead.h"
#include "Sliding.h"
#include "Jumping.h"
#include "Idle.h"

void State::run(Character* d)
{
	printf("Run\n");
	d->setTexture("Run",8);
	d->setCurrent(new Running());
	delete(this);
}
void State::jump(Character* d)
{
	d->setTexture("Jump", 10);
	d->setCurrent(new Jumping());
	delete(this);
}
void State::idle(Character* d)
{
	d->setTexture("Idle", 10);
	d->setCurrent(new Idle());
	delete(this);
}
void State::dead(Character* d)
{
	d->setTexture("Dead", 10);
	d->setCurrent(new Dead());
	delete(this);
}
void State::slide(Character* d)
{
	d->setTexture("Slide", 10);
	d->setCurrent(new Sliding());
	delete(this);
}

void State::update(Character* d, float deltaTime) {
	d->UpdateBackRun(deltaTime);
}