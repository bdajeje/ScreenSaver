#ifndef CURTAINSRENDERER_H
#define CURTAINSRENDERER_H

#include "renderers/texture_renderer.hpp"

class CurtainsRenderer final : public TextureRenderer
{
	enum class Direction {Vertical, Horizontal};

	struct SpriteSpeed {
		float x {0};
		float y {0};
	};

	public:

		CurtainsRenderer(const sf::Texture* current, const sf::Texture* next, uint width, uint height);

	protected:

		virtual bool updateTexture(const sf::Time& elapsed_time, sf::RenderWindow& target) override;

	protected:

		std::array<sf::Sprite, 2> _side_sprites;
		std::array<SpriteSpeed, 2> _sprite_speeds;
};

#endif // CURTAINSRENDERER_H
