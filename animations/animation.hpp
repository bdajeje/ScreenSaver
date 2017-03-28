#ifndef ANIMATION_HPP
#define ANIMATION_HPP

class Animation
{
  public:

    Animation() = default;
    virtual ~Animation() = default;

    bool isFinished() const { return _finished; }
    virtual void finish() { _finished = true; }

    virtual void update(const sf::Time& time) = 0;

  protected:

    bool _finished {false};
};

#endif // ANIMATION_HPP
