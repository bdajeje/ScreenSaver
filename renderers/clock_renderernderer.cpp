#include "clock_renderer.hpp"

ClockRenderer::ClockRenderer(const sf::Texture* current, const sf::Texture* next, uint width, uint height)
	: TextureRenderer {current, next, width, height}
{

}

bool ClockRenderer::updateTexture(const sf::Time& /*elapsed_time*/, sf::RenderWindow& target)
{
  bool updated = false;

// todo

  if(updated)
  {
	target.draw(_current_sprite);
	target.draw(_next_sprite);
  }

  return updated;
}
