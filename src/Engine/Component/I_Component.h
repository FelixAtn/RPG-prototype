#pragma once
class Object;

class I_Component
{
public:
	virtual ~I_Component() = default;
	virtual void Update(float deltaTime) {};
	virtual void Update(Object& object, float deltaTime) {};
	virtual void Draw(Window& window) {};
};