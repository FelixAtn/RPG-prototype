#include "stdafx.h"
#include "RenderingSystem.h"

void RenderingSystem::Unregister(C_Renderable* renderable)
{
	auto it = std::find(m_Renderables.begin(), m_Renderables.end(), renderable);

	if (it != m_Renderables.end())
	{
		m_Renderables.erase(it);
	}
}

void RenderingSystem::Draw(Window& window)
{
	// Drawing order based on Y-position of the sprites/entities for depth effect
	std::sort(m_Renderables.begin(), m_Renderables.end(),
		[](const C_Renderable* first, const C_Renderable* second)
		{
			if (first->GetDrawOrder() != second->GetDrawOrder())
			{
				return first->GetDrawOrder() < second->GetDrawOrder();
			}
			return first->GetDrawingPosition().y < second->GetDrawingPosition().y;
		});

	for (auto* renderable : m_Renderables)
	{
		renderable->Draw(window);
	}
}
