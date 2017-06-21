#ifndef TEXT_HPP
#define TEXT_HPP

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class Text final : public sf::Drawable
				 , public sf::Transformable
{
  public:

	Text(const std::string& text, const sf::Font& font, unsigned int character_size, const sf::Color& color);

	void setPosition(float x, float y);
	void setString(const std::string& string);

  protected:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void adjustBackgroundSize();

  protected:

	sf::Text _text;
	sf::RectangleShape _background;

	static constexpr int _padding {10};

	// \todo: I don't understand why the text/font information from sfml is not correct
	static constexpr int _adjustement_x {0} /*{2}*/;
	static constexpr int _adjustement_y {0} /*{8}*/;
};

#endif // TEXT_HPP
