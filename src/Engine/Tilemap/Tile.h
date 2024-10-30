#pragma once
#include "Engine/Object/Object.h"  // Add the proper include path for Object
#include "Engine/Enums/TileTypeID.h"  // Add the proper include path for TileTypeID


class Tile : public Object
{
public:
	Tile(TileTypeID tileTypeID, const sf::Sprite& sprite,
		const Vector2f& hitboxSize = Vector2f(64.f, 64.f),
		const Vector2f& hitboxOffset = Vector2f(0.0f, 0.0f))
		: m_TileType(tileTypeID)
	{
		// Add sprite component and set the sprite
		auto* spriteComp = AddComponent<C_Sprite>();
		spriteComp->GetSprite() = sprite;

		// Add and init box collider
		auto* collider = AddComponent<C_BoxCollider>();
		collider->Init(spriteComp->GetSprite(), hitboxSize);
	}

	bool IsPassable() const { return m_Passable; }
	void SetPassable(bool passable) { m_Passable = passable; }
	TileTypeID GetTileType() const { return m_TileType; }

private:
	TileTypeID m_TileType;
	bool m_Passable = true;
};




