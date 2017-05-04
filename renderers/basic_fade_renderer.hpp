#ifndef BASICFADERENDERER_HPP
#define BASICFADERENDERER_HPP

#include <memory>

#include "renderers/texture_renderer.hpp"
#include "animations/fading_animation.hpp"

class BasicFadeRenderer final : public TextureRenderer
{
  public:

	BasicFadeRenderer(const sf::Texture* current, const sf::Texture* next, uint width, uint height);

  protected:

	virtual bool updateTexture(const sf::Time& elapsed_time, sf::RenderWindow& target) override;

  private:

	std::unique_ptr<FadingAnimation> _animation_on_current;
	std::unique_ptr<FadingAnimation> _animation_on_next;
};

#endif // BASICFADERENDERER_HPP
