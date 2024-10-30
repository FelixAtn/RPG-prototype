#pragma once

class C_Renderable;

// Observer 
class RenderingSystem
{
public:
	void Register(C_Renderable* renderable) { m_Renderables.emplace_back(renderable); };
	void Unregister(C_Renderable* renderable);
	void Draw(Window& window);

private:
	std::vector<C_Renderable*> m_Renderables;
};

