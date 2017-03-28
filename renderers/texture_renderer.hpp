#ifndef TEXTURERENDERER_HPP
#define TEXTURERENDERER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class TextureRenderer
{
  public:

    TextureRenderer(const sf::Texture& current, const sf::Texture& next);
    virtual ~TextureRenderer() = default;

    /*
     * \returns true if changed has been applied an 'target'
     */
    virtual bool update(const sf::Time& elapsed_time, sf::RenderWindow& target) = 0;

  protected:

    const sf::Texture& _current;
    const sf::Texture& _next;
};

#endif // TEXTURERENDERER_HPP
