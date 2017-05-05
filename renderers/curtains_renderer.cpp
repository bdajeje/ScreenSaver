#include "curtains_renderer.hpp"

#include "utils/graphics.hpp"
#include "utils/math.hpp"
#include "utils/settings.hpp"

CurtainsRenderer::CurtainsRenderer(const sf::Texture* current, const sf::Texture* next, uint screen_width, uint screen_height)
	: TextureRenderer {current, next, screen_width, screen_height}
  , _direction {(utils::random(0,3) <= 1) ? Direction::Vertical : Direction::Horizontal}
{
  const auto& texture_size      = next->getSize();
  const int slice_width         = _direction == Direction::Vertical ? texture_size.x: texture_size.x / 2;
  const int slice_height        = _direction == Direction::Vertical ? texture_size.y / 2: texture_size.y;
  const int slice_screen_width  = _direction == Direction::Vertical ? screen_width : screen_width  / 2;
  const int slice_screen_height = _direction == Direction::Vertical ? screen_height / 2 : screen_height;

	_side_sprites[0].setTexture(*_next, true);
	_side_sprites[1].setTexture(*_next, true);

	_side_sprites[0].setTextureRect(sf::IntRect{0, 0, slice_width, slice_height});
	_side_sprites[1].setTextureRect(sf::IntRect{
    _direction == Direction::Vertical ? 0 : slice_width,
    _direction == Direction::Vertical ? slice_height : 0,
		slice_width, slice_height});

	_side_sprites[0].setPosition(
    _direction == Direction::Vertical ? 0 : -slice_screen_width,
    _direction == Direction::Vertical ? -slice_screen_height : 0
	);

	_side_sprites[1].setPosition(
    _direction == Direction::Vertical ? 0 : screen_width,
    _direction == Direction::Vertical ? screen_height : 0
	);

  graphics::resize(_side_sprites[0], slice_screen_width, slice_screen_height);
  graphics::resize(_side_sprites[1], slice_screen_width, slice_screen_height);

  _animation_time = sf::seconds(Settings::transitionSecs());
  const float animation_time_ms = _animation_time.asMilliseconds();

  _sprite_speeds[0].x = _direction == Direction::Vertical ? 0 : slice_screen_width / animation_time_ms;
  _sprite_speeds[0].y = _direction == Direction::Vertical ? slice_screen_height / animation_time_ms : 0;
	_sprite_speeds[1].x = -_sprite_speeds[0].x;
	_sprite_speeds[1].y = -_sprite_speeds[0].y;
}

bool CurtainsRenderer::updateTexture(const sf::Time& elapsed_time, sf::RenderWindow& target)
{
	target.draw(_current_sprite);

	const auto elapsed_ms = elapsed_time.asMilliseconds();

  if(_total_animation_time < _animation_time)
  {
    _side_sprites[0].move(_sprite_speeds[0].x * elapsed_ms, _sprite_speeds[0].y * elapsed_ms);
    _side_sprites[1].move(_sprite_speeds[1].x * elapsed_ms, _sprite_speeds[1].y * elapsed_ms);
  }
  else
  {
    _side_sprites[0].setPosition(0, 0);
    _side_sprites[1].setPosition(
      _direction == Direction::Vertical ? 0 : _screen_width / 2,
      _direction == Direction::Vertical ? _screen_height / 2 : 0
    );
  }

	target.draw(_side_sprites[0]);
	target.draw(_side_sprites[1]);

	return true;
}
