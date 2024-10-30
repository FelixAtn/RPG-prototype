#pragma once


class Hostile : public Object
{
public:
	Hostile();
	Vector2f UpdateState(Object& target, float deltaTime);
	void Update(Object& target, float deltaTime) override;

private:
	C_Sprite* m_Sprite;
	C_Animation* m_Animation;
	C_Movement* m_Movement;
	C_AttributeData* m_Data;
	C_BoxCollider* m_Collider;
	C_InputHandler* m_Input;

	HostileAI* m_AI;
	PatrolBehaviour* m_PatrolBehaviour;
	ChaseBehaviour* m_ChaseBehaviour;
 	AttackBehaviour* m_AttackBehaviour;
};
