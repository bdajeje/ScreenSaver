#include "basic_fade_renderer.hpp"

#include <SFML/Graphics/RenderTexture.hpp>

#include "utils/settings.hpp"

BasicFadeRenderer::BasicFadeRenderer(const sf::Texture* current, const sf::Texture* next, uint width, uint height)
  : TextureRenderer {current, next, width, height}
{
  sf::Time time = sf::seconds(Settings::transitionSecs());
  _animation_on_current.reset(new FadingAnimation(_current_sprite, time, FadingAnimation::Type::Out, true));
  _animation_on_next.reset(new FadingAnimation(_next_sprite, time, FadingAnimation::Type::In, true));
}

bool BasicFadeRenderer::updateTexture(const sf::Time& elapsed_time, sf::RenderWindow& target)
{
  bool updated = false;

  if(!_animation_on_current->isFinished())
  {
	_animation_on_current->update(elapsed_time);
	updated = true;
  }

  if(!_animation_on_next->isFinished())
  {
	_animation_on_next->update(elapsed_time);
	updated = true;
  }

  if(updated)
  {
	target.draw(_current_sprite);
	target.draw(_next_sprite);
  }

  return updated;
}
