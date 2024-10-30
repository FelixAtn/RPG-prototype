#pragma once
#include "stdafx.h"

enum class TileType
{
	GROUND, // Walkable first layer for tiles
	OBSTACLE, // non-walkable obstacles
	DOOR, // door or portal for level transitions
	PORTAL, // teleport for player to different locations or levels.
	POWER_SWITCH, // to trigger game events
	GRASS, // decorative
	BUSH, // decorative + possibly pick up item ( berries )  
	ROCK, // decorative + possibly mining
	TREE, // decorative + possibly logging 
	SPAWN_POINT, // character spawn points
	CHECKPOINT // to save the progress
};