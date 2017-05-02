#ifndef RECTANGLESRENDERER_H
#define RECTANGLESRENDERER_H

#include "renderers/texture_renderer.hpp"

class RectanglesRenderer final : public TextureRenderer
{
	enum class Direction {Vertical, Horizontal};

	public:

		RectanglesRenderer(const sf::Texture* current, const sf::Texture* next, uint width, uint height);

	protected:

		virtual bool updateTexture(const sf::Time& elapsed_time, sf::RenderWindow& target) override;

	protected:

		Direction _direction;
		std::vector<sf::Sprite> _slices;
		sf::Time _animation_time;
		uint _screen_width;
		uint _screen_height;

//		static const uint _nbr_slices {8};
		static const uint _nbr_slices {2};
};

#endif // RECTANGLESRENDERER_H
