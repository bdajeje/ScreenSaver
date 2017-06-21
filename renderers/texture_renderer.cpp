#include "texture_renderer.hpp"

#include "utils/graphics.hpp"
#include "utils/settings.hpp"

TextureRenderer::TextureRenderer(const sf::Texture* current, const sf::Texture* next, uint width, uint height)
  : _current {current}
  , _next {next}
  , _display_time {sf::seconds(Settings::waitSecs())}
  , _screen_width {width}
  , _screen_height {height}
{
  _current_sprite.setTexture(*current);
  _next_sprite.setTexture(*next);

  // Scale is needed if:
  // - image is bigger than screen
  // - image is smaller than screen and we allow scaling up in settings
  const auto sprite_size = _current_sprite.getGlobalBounds();
  if(sprite_size.width > width || sprite_size.height > height || Settings::scale())
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

void TextureRenderer::update(const sf::Time& elapsed_time, sf::RenderWindow& target)
{
  _total_elapsed_time += elapsed_time;

  if(_total_elapsed_time > _display_time)
  {
	updateTexture(elapsed_time, target);
	_total_animation_time += elapsed_time;
  }
  else
	  target.draw(_current_sprite);
}
