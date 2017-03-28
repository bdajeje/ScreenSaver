#ifndef BASICFADERENDERER_HPP
#define BASICFADERENDERER_HPP

#include "renderers/texture_renderer.hpp"

class BasicFadeRenderer final : public TextureRenderer
{
  public:

    BasicFadeRenderer(const sf::Texture& current, const sf::Texture& next);

    virtual void update(const sf::Time& elapsed_time, sf::Sprite& target) override;

  private:

//    sf::Sprite _current_sprite;
//    sf::Sprite _next_sprite;
};

#endif // BASICFADERENDERER_HPP
