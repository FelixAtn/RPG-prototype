#include "stdafx.h"
#include "C_AttributeData.h"

C_AttributeData::C_AttributeData(const std::string& objectName)
	: m_Name(objectName)
	, m_Damage(0)
	, m_Health(0)
	, m_Cooldown(0)
	, m_MovementSpeed(0)
	, m_Luck(0)
	, m_Level(0)
	, m_Experience(0)
	, m_AttackRange(50.0f)
{
	YAML::Node attributesFile = ResourceManager::Get().GetCharacterFile();
	auto attribute = attributesFile[m_Name]["ATTRIBUTES"];

	//m_Name = attribute["name"].as<std::string>();
	m_Health = attribute["health"].as<float>();
	m_Damage = attribute["damage"].as<float>();
	m_MovementSpeed = attribute["movementSpeed"].as<float>();
	m_Level = attribute["level"].as<int>();
	m_Experience = attribute["experience"].as<float>();
	m_Luck = attribute["luck"].as<float>();
}



