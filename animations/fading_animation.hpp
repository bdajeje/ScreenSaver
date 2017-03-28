#ifndef FADING_ANIMATION_HPP
#define FADING_ANIMATION_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "animations/animation.hpp"

class FadingAnimation final : public Animation
{
  public:

    enum class Type { In, Out };

    FadingAnimation(sf::Sprite& sprite, const sf::Time& time, Type type, bool start = true);

    virtual void update(const sf::Time& elapsed_time) override;
    void start() noexcept;

  private:

    sf::Sprite& _sprite;
    const int _time;
    int _elapsed_time {0};
    Type _type;
    bool _started;
};


#endif // FADING_ANIMATION_HPP
