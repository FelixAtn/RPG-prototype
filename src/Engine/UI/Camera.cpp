#include "stdafx.h"
#include "Camera.h"

Camera::Camera(Window& window, const Vector2f& initialSize)
	: m_Window(window)
{
	m_View.setSize(initialSize);
	m_View.setCenter(initialSize * DIVISOR);
	m_OriginalSize = initialSize;
}

void Camera::Reset()
{
	m_View.setCenter(m_OriginalSize * DIVISOR);
}

