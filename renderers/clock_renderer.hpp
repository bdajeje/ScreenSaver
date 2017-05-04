#ifndef CLOCKRENDERER_H
#define CLOCKRENDERER_H

#include "renderers/texture_renderer.hpp"

class ClockRenderer final : public TextureRenderer
{
	public:

		ClockRenderer(const sf::Texture* current, const sf::Texture* next, uint width, uint height);

	protected:

	  virtual bool updateTexture(const sf::Time& elapsed_time, sf::RenderWindow& target) override;

	protected:

		sf::Image _image;
		sf::Texture _updated_next_texture;
//		sf::Uint8* _pixels;
//		sf::Sprite _updated_next_sprite;
};

#endif // CLOCKRENDERER_H
