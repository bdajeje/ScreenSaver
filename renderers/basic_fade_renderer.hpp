#ifndef BASICFADERENDERER_HPP
#define BASICFADERENDERER_HPP

#include "renderers/texture_renderer.hpp"
#include "animations/fading_animation.hpp"

class BasicFadeRenderer final : public TextureRenderer
{
  public:

    BasicFadeRenderer(const sf::Texture& current, const sf::Texture& next);
    ~BasicFadeRenderer();

    virtual bool update(const sf::Time& elapsed_time, sf::RenderWindow& target) override;

  private:

    sf::Sprite _current_sprite;
    sf::Sprite _next_sprite;
    FadingAnimation* _animation_on_current;
    FadingAnimation* _animation_on_next;    
};

#endif // BASICFADERENDERER_HPP
