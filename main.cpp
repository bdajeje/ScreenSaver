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
sf::Sprite Target;
std::unique_ptr<TextureRenderer> Renderer;

void handleEvents()
{
  sf::Event event;
  while(Window->pollEvent(event))
  {
    // Close program
    if( event.type == sf::Event::KeyPressed )
      Window->close();
      return;
  }
}

void draw()
{
  Window->clear(ClearColor);
  Window->draw(Target);
  Window->display();
}

void updateTexture(const sf::Time& elapsed_time)
{
  Renderer->update(elapsed_time, Target);
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

  Renderer.reset(new BasicFadeRenderer(Image_list->current(), Image_list->next()));

  Window.reset(new sf::RenderWindow({sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height}, "", sf::Style::None));
  Window->setFramerateLimit(60);

  utils::time::Timer timer;

  while(Window->isOpen())
  {
    const sf::Time elapsed_time {timer.restart()};
    handleEvents();
    updateTexture(elapsed_time);
    draw();
  }

  return EXIT_SUCCESS;
}
