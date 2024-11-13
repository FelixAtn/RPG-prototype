#pragma once

class Object
{
public:

	virtual ~Object() = default;
	virtual void Update(float deltaTime) {};
	virtual void Update(Object& object, float deltaTime) {};
	virtual void HandleInput(float deltaTime) {};
	virtual void HandleCollision(Object& other, float pushValue) {};
	virtual void HandleObjectInteractions(Object& other, float deltaTime) {};

	template<typename AnyContainer>
	static void HandleAllCollisions(AnyContainer& objects, float pushValue)
	{
		for (size_t i = 0; i < objects.size(); ++i)
		{
			for (size_t j = i + 1; j < objects.size(); ++j)
			{
				auto& first = objects[i];
				auto& second = objects[j];

				if (first && second)
				{
					C_BoxCollider* firstCollider = first->GetComponent<C_BoxCollider>();
					C_BoxCollider* secondCollider = second->GetComponent<C_BoxCollider>();

					if (firstCollider && secondCollider)
					{
						//Debug::Print("CHECKING COLLISION");
						firstCollider->CheckAndResolve(*secondCollider, pushValue);
						secondCollider->CheckAndResolve(*firstCollider, pushValue);
					}
				}
			}
		}
	}

	void RegisterToRendering(RenderingSystem& renderingSystem)
	{
		if (auto* renderable = GetComponent<C_Renderable>())
		{
			renderingSystem.Register(renderable);
		}
	}
	void UnregisterFromRendering(RenderingSystem& renderingSystem)
	{
		if (auto* renderable = GetComponent <C_Renderable>())
		{
			renderingSystem.Unregister(renderable);
		}
	}

	template <typename T, typename... Args>
	T* AddComponent(Args&&... args)
	{
		if (auto component = GetComponent<T>())
		{
			Log::Print("Component already exists!", LogLevel::WARNING);
			return component;
		}

		m_Components.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
		return static_cast<T*>(m_Components.back().get());
	}

	template <typename T>
	T* GetComponent() const
	{
		for (const auto& component : m_Components)
		{
			if (auto* castComponent = dynamic_cast<T*>(component.get()))
			{
				return castComponent;
			}
		}
		return nullptr;
	}

protected:
	std::vector<std::unique_ptr<I_Component>> m_Components;
};