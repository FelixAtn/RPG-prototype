 #pragma once


class PatrolBehaviour : public I_Component
{
public:
	PatrolBehaviour(Object& object, float radius = 100.0f, float updateInterval = 3.0f);
	Vector2f UpdatePatrol(float deltaTime);

private:
	Vector2f GetRandomPatrolPoint(const Vector2f& currentPosition) const;

private:
	C_Sprite* m_Sprite;
	C_AttributeData* m_Data;
	float m_PatrolRadius;
	Timer m_PatrolTimer;
	Vector2f m_PatrolPoint;
	static RandomGenerator s_Random;
};

