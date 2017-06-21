#ifndef TEXTURERENDERER_HPP
#define TEXTURERENDERER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class TextureRenderer
{
  public:

	TextureRenderer(const sf::Texture* current, const sf::Texture* next, uint width, uint height);
	virtual ~TextureRenderer() = default;

	/*
	 * \returns true if changed has been applied an 'target'
	 */
	void update(const sf::Time& elapsed_time, sf::RenderWindow& target);

  protected:

	virtual bool updateTexture(const sf::Time& elapsed_time, sf::RenderWindow& target) = 0;

  protected:

	const sf::Texture* _current;
	const sf::Texture* _next;
	sf::Sprite _current_sprite;
	sf::Sprite _next_sprite;
	sf::Time _total_elapsed_time;
	sf::Time _total_animation_time;
	sf::Time _display_time;
	uint _screen_width;
	uint _screen_height;
};

#endif // TEXTURERENDERER_HPP
