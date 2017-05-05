#include "clock_renderer.hpp"

ClockRenderer::ClockRenderer(const sf::Texture* current, const sf::Texture* next, uint width, uint height)
	: TextureRenderer {current, next, width, height}
	, _updated_next_texture {*next}
{
	_next_sprite.setTexture(_updated_next_texture);

	_image = _updated_next_texture.copyToImage();
//	const sf::Vector2u& size = image.getSize();
//	_pixels = new sf::Uint8[size.x * size.y * 4];

	_a.x = width / 2;
	_a.y = -(height / 2);
	_b.x = width;
	_b.y = _a.y;
}

bool ClockRenderer::updateTexture(const sf::Time& /*elapsed_time*/, sf::RenderWindow& target)
{
  // \todo: instead of re-creating the array of pixels at each frame, simply update the part that needs to be updated

  const sf::Vector2u& size = _image.getSize();
  utils::Point2D point;

  // For now let's have c.x always equal too b.x (so only for quarter of the algo will work)
  utils::Point2D c {_b.x, 0}; // \todo calculate Y from current angle

  for(size_t y = 0; y < size.y; ++y)
  {
	point.y = -y;

	for(size_t x = 0; x < size.x; ++x)
	{
		point.x = x;

		/*
		// just to test: let's make some pixels red
		if(y % 2 == 0 && x % 2 == 0)
//			_pixels[y * x * 4] = ;
//			_image.setPixel(x, y, sf::Color::Red);
			_image.setPixel(x, y, sf::Color::Red);
			*/

		if(utils::pointInTriangle(point, _a, _b, c))
			_image.setPixel(x, y, sf::Color::Red);
	}
  }

//  _updated_next_texture.update(_pixels);
  _updated_next_texture.update(_image);

  target.draw(_current_sprite);
  target.draw(_next_sprite);

  return true;
}
