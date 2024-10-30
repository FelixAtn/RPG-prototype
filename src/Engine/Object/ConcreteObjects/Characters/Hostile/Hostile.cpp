#include "stdafx.h"
#include "Hostile.h"

Hostile::Hostile()
{
	m_Sprite = AddComponent<C_Sprite>("player_spritesheet");
	m_Data = AddComponent<C_AttributeData>("PLAYER");
	m_Movement = AddComponent<C_Movement>(*this);
	m_Animation = AddComponent<C_Animation>(*this);
	m_Input = AddComponent<C_InputHandler>(*this);
	m_Collider = AddComponent<C_BoxCollider>();

	m_Data->SetAttackRange(40);

	// ********************* Temporary **********************
	float patrolRadius = 100.0f;
	float patrolInterval = 3.0f;
	float attackInterval = 1.0f;
	float detectionRange = 200.0f;
	float attackRange = m_Data->GetAttackRange();
	// *********************************************************

	m_AI = AddComponent<HostileAI>(detectionRange, attackRange);
	m_PatrolBehaviour = AddComponent<PatrolBehaviour>(*this, patrolRadius, patrolInterval);
	m_AttackBehaviour = AddComponent<AttackBehaviour>(attackInterval);
	m_ChaseBehaviour = AddComponent<ChaseBehaviour>(*this);

	m_Data->SetMovementSpeed(50);
	m_Collider->Init(m_Sprite->GetSprite(), Vector2f(32, 32));
}

Vector2f Hostile::UpdateState(Object& target, float deltaTime)
{
	Vector2f currentPosition = m_Sprite->GetSprite().getPosition();
	Vector2f targetPosition = target.GetComponent<C_Sprite>()->GetSprite().getPosition();

	m_AI->UpdateTarget(currentPosition, targetPosition);
	m_AI->UpdateState(currentPosition);

	Vector2f velocity;

	switch (m_AI->GetState())
	{
	case HostileEntityState::PATROL:
		return velocity = m_PatrolBehaviour->UpdatePatrol(deltaTime);
		break;

	case HostileEntityState::CHASE:
		return velocity = m_ChaseBehaviour->Update(target);
		break;

	case HostileEntityState::ATTACK:
		if (m_AttackBehaviour->CanAttack(deltaTime))
		{
			m_Animation->PlayAction(AnimationID::SPELL_ATTACK_RIGHT);
			// TODO: Implement attack logic 
		}

		return velocity = Vector2f(0.0f, 0.0f); // Stop moving when attacking
		break;

	default:
		return velocity = Vector2f(); // Default to not move
		break;
	}
}

void Hostile::Update(Object& target, float deltaTime)
{
	Vector2f updatedVelocity = UpdateState(target, deltaTime);
	bool isMoving = updatedVelocity.Length() > 0;

	m_Movement->SetVelocity(updatedVelocity);
	m_Movement->Update(deltaTime);
	m_Animation->UpdateMovementState(isMoving);
	m_Animation->Update(deltaTime);
	m_Collider->Update();
}

