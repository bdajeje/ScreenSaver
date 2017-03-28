#include "basic_fade_renderer.hpp"

#include <SFML/Graphics/RenderTexture.hpp>

BasicFadeRenderer::BasicFadeRenderer(const sf::Texture& current, const sf::Texture& next)
  : TextureRenderer{current, next}
{
  _current_sprite.setTexture(current);
  _next_sprite.setTexture(next);

  sf::Time time = sf::seconds(5);
  _animation_on_current = new FadingAnimation(_current_sprite, time, FadingAnimation::Type::Out, true);
  _animation_on_next = new FadingAnimation(_next_sprite, time, FadingAnimation::Type::In, true);
}

BasicFadeRenderer::~BasicFadeRenderer()
{
  delete _animation_on_current;
  delete _animation_on_next;
}

bool BasicFadeRenderer::update(const sf::Time& elapsed_time, sf::RenderWindow& target)
{
  if(!_animation_on_current->isFinished())
    _animation_on_current->update(elapsed_time);

  if(!_animation_on_next->isFinished())
    _animation_on_next->update(elapsed_time);

  target.draw(_current_sprite);
  target.draw(_next_sprite);

  return true;
}
