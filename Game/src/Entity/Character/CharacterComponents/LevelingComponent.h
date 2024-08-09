#pragma once
class LevelingComponent
{
public:
	LevelingComponent();
	int GetLevel() const;
	int GetExp() const;

	void SetLevel(int level);
	void SetExp(int experience);

private:
	int m_Level; 
	int m_Experience ;
};

