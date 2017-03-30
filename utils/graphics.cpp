#include "utils/graphics.hpp"

namespace graphics {

void centerPosition(sf::Sprite& sprite, unsigned int total_width, unsigned int total_height)
{
  const sf::FloatRect bounds = sprite.getGlobalBounds();
  sprite.setPosition( (total_width - bounds.width) / 2, (total_height - bounds.height) / 2 );
}

void resize(sf::Sprite& sprite, float x, float y)
{
  sprite.setScale( x / sprite.getLocalBounds().width,
                   y / sprite.getLocalBounds().height );
}

}
