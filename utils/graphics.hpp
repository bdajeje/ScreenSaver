#ifndef UTILS_GRAPHICS_HPP
#define UTILS_GRAPHICS_HPP

#include <SFML/Graphics/Sprite.hpp>

namespace graphics {

void centerPosition(sf::Sprite& sprite, unsigned int total_width, unsigned int total_height);
void resize(sf::Sprite& sprite, float x, float y);

}

#endif // UTILS_GRAPHICS_HPP
