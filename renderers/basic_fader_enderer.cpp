#include "basic_fade_renderer.hpp"

BasicFadeRenderer::BasicFadeRenderer(const sf::Texture& current, const sf::Texture& next)
  : TextureRenderer{current, next}
{
//  _current_sprite.setTexture(*current);
//  _next_sprite.setTexture(*next);
}

void BasicFadeRenderer::update(const sf::Time& elapsed_time, sf::Sprite& target)
{
  _elapsed_time += elapsed_time;

  target.setTexture(_current);
}
