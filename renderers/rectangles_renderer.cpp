#include "rectangles_renderer.hpp"

#include "utils/graphics.hpp"
#include "utils/math.hpp"
#include "utils/settings.hpp"

RectanglesRenderer::RectanglesRenderer(const sf::Texture* current, const sf::Texture* next, uint width, uint height)
	: TextureRenderer {current, next, width, height}
//	, _direction {(utils::random(0,2) <= 1) ? Direction::Vertical : Direction::Horizontal}
	, _direction {Direction::Vertical}
	, _animation_time {sf::seconds(Settings::transitionSecs())}
	, _screen_width {width}
	, _screen_height {height}
{
	// Create slices
	_slices.resize(_nbr_slices);

	const auto& texture_size      = current->getSize();
	const int slice_width         = _direction == Direction::Vertical ? texture_size.x / _nbr_slices : texture_size.x;
	const int slice_height        = _direction == Direction::Vertical ? texture_size.y : texture_size.y / _nbr_slices;
	const int slice_screen_width  = _direction == Direction::Vertical ? _screen_width / _nbr_slices : _screen_width;
	const int slice_screen_height = _direction == Direction::Vertical ? _screen_height : _screen_height / _nbr_slices;

	for(size_t i = 0; i < _nbr_slices; ++i)
	{
		sf::Sprite& sprite = _slices[i];
		sprite.setTexture(*_current, true);
//		sprite.setTexture(*_current);

		sprite.setPosition(0,0);

//		sprite.setPosition(
//			_direction == Direction::Vertical ? i * slice_width : 0,
//			_direction == Direction::Vertical ? 0 : i * slice_height
//		);


		// THIS BUGS
		sprite.setTextureRect(sf::IntRect{
			_direction == Direction::Vertical ? i * slice_width : 0,
			_direction == Direction::Vertical ? 0 : i * slice_height,
			slice_width, slice_height});

		graphics::resize(sprite, slice_screen_width, slice_screen_height);
	}
}

bool RectanglesRenderer::updateTexture(const sf::Time& /*elapsed_time*/, sf::RenderWindow& target)
{
//  target.draw(_next_sprite);

  uint i = 0;
  int x, y;
  for(auto& sprite : _slices)
  {
//	  const auto& pos = sprite.getPosition();
//	  x = _direction == Direction::Vertical ? pos.x : _total_elapsed_time.asMilliseconds() * _screen_width / _animation_time.asMilliseconds();
//	  y = _direction == Direction::Vertical ? _total_elapsed_time.asMilliseconds() * _screen_height / _animation_time.asMilliseconds() : pos.y;
//	  sprite.setPosition(x, y);
	  ++i;
//	  std::cout << sprite.getPosition().x << '/' << sprite.getPosition().y << " | " << sprite.getGlobalBounds().width << '/' << sprite.getGlobalBounds().height << std::endl;
	  target.draw(sprite);
  }

  return true;
}
