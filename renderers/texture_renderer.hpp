#ifndef TEXTURERENDERER_HPP
#define TEXTURERENDERER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>

class TextureRenderer
{
  public:

    TextureRenderer(const sf::Texture& current, const sf::Texture& next);
    virtual ~TextureRenderer() = default;

    virtual void update(const sf::Time& elapsed_time, sf::Sprite& target) = 0;

  protected:

    const sf::Texture& _current;
    const sf::Texture& _next;
    sf::Time _elapsed_time;
};

#endif // TEXTURERENDERER_HPP
