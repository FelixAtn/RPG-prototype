#pragma once

class Player : public Object
{
public:
	Player();

	void HandleCollision(Object& other, float pushValue) override;
	void Update(float deltaTime) override;
	void HandleObjectInteractions(Object& other, float deltaTime) override;
	void Draw(Window& window);
	std::vector<C_Sprite> m_Projectile;

private:
	Timer m_Timer;
	C_Sprite* m_Sprite;
	C_Animation* m_Animation;
	C_Movement* m_Movement;
	C_AttributeData* m_Data;
	C_BoxCollider* m_Collider;
	C_InputHandler* m_Input;
	C_Shoot* m_Shoot;
	Vector2f projMovingOffset;
};