#include "texture_renderer.hpp"

#include "utils/graphics.hpp"
#include "utils/settings.hpp"

TextureRenderer::TextureRenderer(const sf::Texture& current, const sf::Texture& next, uint width, uint height)
  : _current {current}
  , _next {next}
  , _display_time {sf::seconds(Settings::waitSecs())}
{
  _current_sprite.setTexture(current);
  _next_sprite.setTexture(next);

  if(Settings::scale())
  {
    graphics::resize(_current_sprite, width, height);
    graphics::resize(_next_sprite, width, height);
  }
  else
  {
    graphics::centerPosition(_current_sprite, width, height);
    graphics::centerPosition(_next_sprite, width, height);
  }
}

bool TextureRenderer::update(const sf::Time& elapsed_time, sf::RenderWindow& target)
{
  bool updated = false;

  // In case first time we enter this method, draw image
  if(_total_elapsed_time == sf::Time::Zero)
  {
    target.draw(_current_sprite);
    updated = true;
  }

  _total_elapsed_time += elapsed_time;

  if(_total_elapsed_time > _display_time)
    updated = updateTexture(elapsed_time, target);

  return updated;
}
