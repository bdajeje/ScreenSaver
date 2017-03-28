#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include "utils/settings.hpp"
#include "utils/timer.hpp"
#include "renderers/basic_fade_renderer.hpp"
#include "image_list.hpp"

std::unique_ptr<ImageList> Image_list;
std::unique_ptr<sf::RenderWindow> Window;
const sf::Color ClearColor = sf::Color::Black;
std::unique_ptr<TextureRenderer> Renderer;
//sf::RenderTexture Target;
//sf::Sprite Sprite;
sf::Event event;

void handleEvents()
{
  while(Window->pollEvent(event))
  {
    // Close program
    if( event.type == sf::Event::KeyPressed )
      Window->close();
      return;
  }
}

void draw(const sf::Time& elapsed_time)
{
  Window->clear(ClearColor);
  Renderer->update(elapsed_time, *Window);
  Window->display();
}

int main(/*int argc, char *argv[]*/)
{
  Settings::init("settings.json");
  Image_list.reset(new ImageList);

  if(!Image_list->isValid())
  {
    std::cerr << "Target directory must contains at least two png images.";
    return EXIT_FAILURE;
  }

//  _texture.create(size.x, size.y);

  const sf::Vector2u window_size {sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height};
  Renderer.reset(new BasicFadeRenderer(Image_list->current(), Image_list->next()));

  Window.reset(new sf::RenderWindow({window_size.x, window_size.y}, "", sf::Style::None));
  Window->setFramerateLimit(60);

//  Sprite.setTexture(Target.getTexture());
  utils::time::Timer timer;

  while(Window->isOpen())
  {
    const sf::Time elapsed_time {timer.restart()};
    handleEvents();
    draw(elapsed_time);
  }

  return EXIT_SUCCESS;
}
