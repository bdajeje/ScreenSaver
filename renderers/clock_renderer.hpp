#ifndef CLOCKRENDERER_H
#define CLOCKRENDERER_H

#include "renderers/texture_renderer.hpp"

class ClockRenderer final : public TextureRenderer
{
	public:

		ClockRenderer(const sf::Texture* current, const sf::Texture* next, uint width, uint height);

	protected:

	  virtual bool updateTexture(const sf::Time& elapsed_time, sf::RenderWindow& target) override;
};

#endif // CLOCKRENDERER_H
