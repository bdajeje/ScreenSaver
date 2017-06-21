#ifndef TEXT_HPP
#define TEXT_HPP

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>

class Text : public sf::Drawable
		   , public sf::Transformable
{
  public:

	Text(const std::string text, const sf::Font& font, unsigned int character_size, const sf::Color& color);

	void setPosition(float x, float y);
	void setString(const std::string& string);

  protected:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  protected:

	sf::Text _text;
	sf::RectangleShape _background;

	static constexpr int _padding {10};

	// \todo: I don't understand why the text/font information from sfml is not correct
	static constexpr int _adjustement_x {2};
	static constexpr int _adjustement_y {8};
};

#endif // TEXT_HPP
