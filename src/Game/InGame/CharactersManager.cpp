#include "stdafx.h"
#include "CharactersManager.h"

CharactersManager::CharactersManager(RenderingSystem& renderingSystem)
	: m_RenderingSystem(renderingSystem)
{
    m_HostileEntities.reserve(50);
}

void CharactersManager::InitPlayer(const Vector2f& position)
{

	if (C_Sprite* spriteComponent = m_Player.GetComponent<C_Sprite>())
	{
		spriteComponent->GetSprite().setPosition(position);
		m_RenderingSystem.Register(spriteComponent);
	}
}

void CharactersManager::HandleInput()
{

}

void CharactersManager::Update(float deltaTime)
{
    m_Player.Update(deltaTime);
    for (auto& monster : m_HostileEntities)
    {
        if (monster != nullptr)
        {
            monster->Update(m_Player, deltaTime);;
            m_Player.HandleCollision(*monster, 0.0f);
			m_Player.HandleObjectInteractions(*monster, deltaTime);
        }
    }
    Object::HandleAllCollisions(m_HostileEntities, 0.0f);

	RemoveDeadCharacters();
}

void CharactersManager::Draw(Window& window)
{
	m_Player.Draw(window);
}

void CharactersManager::RemoveDeadCharacters()
{
	m_HostileEntities.erase
	(
		std::remove_if(m_HostileEntities.begin(), m_HostileEntities.end(), [this](const std::unique_ptr<Object>& hostile)
			{
				if (hostile != nullptr && hostile->GetComponent<C_AttributeData>()->IsDead())
				{
					// Unregistering deads from the renderer
					hostile->UnregisterFromRendering(m_RenderingSystem);
					return true; 
				}
				return false; // Keep alive hostiles
			}),

		m_HostileEntities.end() // Actual removal
	);
}
