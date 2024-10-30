#pragma once
constexpr float PI = 3.141592f;

class C_Movement : public I_Component
{
public:
	C_Movement(Object& object);
	
	//Updates
	void Update(float deltaTime) override;
	void UpdateDirection();

	// Getters
	inline Vector2f GetVelocity() const { return m_Velocity; }
	inline Vector2f GetPreviousVelocity() const { return m_PreviousVelocity; }
	inline Direction GetCurrentDirection() const { return m_CurrentDirection; }
	inline Direction GetPreviousDirection() const { return m_PreviousDirection; }

	// Setters
	void SetVelocity(Vector2f velocity);
	void SetMaxSpeed(float maxSpeed) { m_MaxSpeed = maxSpeed; }

private:
	// Members
	C_Sprite* m_Sprite;
	C_AttributeData* m_Data;
	Vector2f m_DirectionOffset;
	Vector2f m_Velocity;
	Vector2f m_PreviousVelocity;
	Vector2f m_TargetVelocity;
	Direction m_CurrentDirection;
	Direction m_PreviousDirection;
	float m_MaxSpeed;
};

