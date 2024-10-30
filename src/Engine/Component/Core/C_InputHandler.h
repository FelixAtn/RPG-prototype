#pragma once

class C_Animation;
class C_Movement;
class C_AttributeData;

class C_InputHandler : public I_Component
{
public:
	C_InputHandler(Object& object);
	void Update(Object& other, float deltaTime) override;

private:
	C_Animation* m_Animation;
	C_Movement* m_Movement;
	C_AttributeData* m_Data;

};

