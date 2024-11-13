#pragma once
// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <algorithm>
#include <array>
#include <cmath>
#include <thread>
#include <fstream>
#include <istream>
#include <ostream>
#include <bitset>
#include <cstdint>
#include <random>
#include <functional>
#include <any>

#define YAML_CPP_STATIC_DEFINE
// YAML PARSER
#include <yaml-cpp/yaml.h>


#include <imgui/imgui.h>
#include <imgui/imgui-SFML.h>

// SFML includes
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

// Utilities
#include "Engine/Utility/Log.h"
#include "Engine/Utility/Vector2.h"
#include "Engine/Utility/Timer.h"
#include "Engine/Utility/RandomGen.h"

// Enums
#include "Engine/Enums/Direction.h"
#include "Engine/Enums/AnimationID.h"
#include "Engine/Enums/TileTypeID.h"
#include "Engine/Enums/WorldMaps.h"

// Managers
// #include "Managers/AssetManager.h"
// #include "Managers/SettingsManager.h"
// #include "Managers/ViewManager.h"
#include "Engine/Managers/ResourceManager.h"
#include "Engine/Managers/Window.h"
#include "Engine/Managers/AudioManager.h"
#include "Engine/Managers/StateManager.h"
#include "Engine/Managers/InputManager.h"
#include "Engine/Managers/RenderingSystem.h"

// UI 
#include "Engine/UI/Camera.h"
#include "Engine/UI/Minimap.h"
#include "Engine/UI/Cursor.h"


// States
// #include "Game/InGame/Components/States/InDead.h"
// #include "Game/InGame/Components/States/InIdle.h"
// #include "Game/InGame/Components/States/InInteraction.h"
// #include "Game/InGame/Components/States/InMove.h"

// Components
#include "Engine/Component/I_Component.h"
#include "Engine/Component/Core/C_Renderable.h"
#include "Engine/Component/Core/C_InputHandler.h"
#include "Engine/Component/Gameplay/C_AttributeData.h"
#include "Engine/Component/Gameplay/C_Movement.h"
#include "Engine/Component/Gameplay/C_Shoot.h"
#include "Engine/Component/Animation/C_Animation.h"
#include "Engine/Component/Colliders/C_BoxCollider.h"
#include "Engine/Component/AI/HostileAI.h"
#include "Engine/Component/AI/PatrolBehaviour.h"
#include "Engine/Component/AI/ChaseBehaviour.h"
#include "Engine/Component/AI/AttackBehaviour.h"

#include "Engine/Tilemap/Tile.h"
#include "Engine/Tilemap/TileLayer.h"
#include "Engine/Object/Object.h"
#include "Engine/Object/ConcreteObjects/Characters/Hostile/Hostile.h"
#include "Engine/Object/ConcreteObjects/Characters/Player/Player.h"
#include "Engine/Object/ConcreteObjects/Characters/NPC/NPC.h"

// NLOHMAN JSON
// #include "Utilities/json.hpp"
// 
// Engine includes
// #include "Systems/Music.h"
// #include "Systems/Window.h"
// #include "Utilities/Utility."  
// 
// #include "Systems/StateMachine.h"
// #include "Components/I_Component.h"
// #include "Components/Drawables/C_Sprite.h"
// #include "Components/Drawables/C_Text.h"
// #include "Object/Object.h"
// #include "GUI/Button.h"





// WIN Dependencies
#include <windows.h>

#include <sstream>
