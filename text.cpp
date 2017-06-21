#include "text.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

Text::Text(const std::string& text, const sf::Font& font, unsigned int character_size, const sf::Color& color)
  : _text {"", font, character_size}
{
  _text.setColor(color);
  setString(text);
  _background.setFillColor(sf::Color{0, 0, 0, 200});
}

void Text::setPosition(float x, float y)
{
  _background.setPosition(x, y);
  _text.setPosition(
	x + _padding + _adjustement_x,
	y + _padding - _adjustement_y
  );
}

void Text::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(_background, states);
  target.draw(_text, states);
}

void Text::setString(const std::string& string)
{
  _text.setString(string);
  adjustBackgroundSize();
}

void Text::adjustBackgroundSize()
{
	const auto text_size = _text.getGlobalBounds();
	_background.setSize({text_size.width + 2 * _padding + _adjustement_x, text_size.height + 2 * _padding + _adjustement_y});
}
