#include "curtains_renderer.hpp"

#include "utils/graphics.hpp"
#include "utils/math.hpp"
#include "utils/settings.hpp"

CurtainsRenderer::CurtainsRenderer(const sf::Texture* current, const sf::Texture* next, uint screen_width, uint screen_height)
	: TextureRenderer {current, next, screen_width, screen_height}
{
	const Direction direction = (utils::random(0,3) <= 1) ? Direction::Vertical : Direction::Horizontal;

	const auto& texture_size      = next->getSize();
	const int slice_width         = direction == Direction::Vertical ? texture_size.x: texture_size.x / 2;
	const int slice_height        = direction == Direction::Vertical ? texture_size.y / 2: texture_size.y;
	const int slicescreen_width  = direction == Direction::Vertical ? screen_width : screen_width  / 2;
	const int slicescreen_height = direction == Direction::Vertical ? screen_height / 2 : screen_height;

	_side_sprites[0].setTexture(*_next, true);
	_side_sprites[1].setTexture(*_next, true);

	_side_sprites[0].setTextureRect(sf::IntRect{0, 0, slice_width, slice_height});
	_side_sprites[1].setTextureRect(sf::IntRect{
		direction == Direction::Vertical ? 0 : slice_width,
		direction == Direction::Vertical ? slice_height : 0,
		slice_width, slice_height});

	_side_sprites[0].setPosition(
		direction == Direction::Vertical ? 0 : -slicescreen_width,
		direction == Direction::Vertical ? -slicescreen_height : 0
	);

	_side_sprites[1].setPosition(
		direction == Direction::Vertical ? 0 : screen_width,
		direction == Direction::Vertical ? screen_height : 0
	);

	graphics::resize(_side_sprites[0], slicescreen_width, slicescreen_height);
	graphics::resize(_side_sprites[1], slicescreen_width, slicescreen_height);

	const float animation_time = sf::seconds(Settings::transitionSecs()).asMilliseconds();

	_sprite_speeds[0].x = direction == Direction::Vertical ? 0 : slicescreen_width / animation_time;
	_sprite_speeds[0].y = direction == Direction::Vertical ? slicescreen_height / animation_time : 0;
	_sprite_speeds[1].x = -_sprite_speeds[0].x;
	_sprite_speeds[1].y = -_sprite_speeds[0].y;
}

bool CurtainsRenderer::updateTexture(const sf::Time& elapsed_time, sf::RenderWindow& target)
{
	target.draw(_current_sprite);

	const auto elapsed_ms = elapsed_time.asMilliseconds();
	_side_sprites[0].move(_sprite_speeds[0].x * elapsed_ms, _sprite_speeds[0].y * elapsed_ms);
	_side_sprites[1].move(_sprite_speeds[1].x * elapsed_ms, _sprite_speeds[1].y * elapsed_ms);

	target.draw(_side_sprites[0]);
	target.draw(_side_sprites[1]);

	return true;
}
