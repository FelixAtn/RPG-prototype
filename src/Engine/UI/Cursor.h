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

    void Update(Window& window);

    void Draw(Window& window);

    const Vector2i& GetPosition() const { return m_CursorPosition; }

private:
    Cursor() = default; // Private constructor to prevent instantiation
    sf::Sprite m_CursorSprite; ///< The SFML cursor.
    Vector2i m_CursorPosition;

};
