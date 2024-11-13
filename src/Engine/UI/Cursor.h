#pragma once

class Cursor
{
public:

    static Cursor& Get()
    {
        static Cursor instance; 
        return instance;
    }

    Cursor(const Cursor&) = delete;
    Cursor& operator=(const Cursor&) = delete;


    void SetTexture(const std::string& textureName);

    void Update();

    void Draw(Window& window);

    const Vector2i& GetPosition() const { return m_CursorPosition; }

private:
    Cursor() = default;
    sf::Sprite m_CursorSprite; 
    Vector2i m_CursorPosition;
    Window* m_Window;
};
