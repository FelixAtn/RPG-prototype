#pragma once


class ChaseBehaviour : public I_Component
{
public:
	ChaseBehaviour(Object& object);

	Vector2f Update(Object& other);


private:
	C_Sprite* m_Sprite;
	C_AttributeData* m_Data;
	C_Movement* m_Movement;
};

