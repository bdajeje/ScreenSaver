#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>

#include "utils/settings.hpp"
#include "utils/timer.hpp"
#include "renderers/basic_fade_renderer.hpp"
#include "image_list.hpp"

std::unique_ptr<ImageList> Image_list;
std::unique_ptr<sf::RenderWindow> Window;
std::unique_ptr<TextureRenderer> Renderer;
std::unique_ptr<sf::Text> ImageName;
const sf::Color ClearColor = sf::Color::Black;
sf::Event event;
sf::Font font;

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

  if (ImageName)
    Window->draw(*ImageName);

  Window->display();
}

TextureRenderer* createRenderer(const std::string& name)
{
  if(name == "BasicFade")
    return new BasicFadeRenderer(Image_list->current(), Image_list->next());
  // else if(name == "Rain")
  //   return new RainRenderer(Image_list->current(), Image_list->next());

  // Always return a valid renderer
  return new BasicFadeRenderer(Image_list->current(), Image_list->next());
}

void pickRenderer()
{
  const auto& renderers = Settings::renderers();
  const int random_offset = rand() % renderers.size();
  Renderer.reset(createRenderer(renderers[random_offset]));
}

void next()
{
  Image_list->loadNext();
  pickRenderer();

  if(ImageName)
    ImageName->setString(Image_list->currentFileName());
}

void createImageName()
{
  ImageName.reset(new sf::Text);
  ImageName->setCharacterSize(45);
//  ImageName->setFillColor(sf::Color::White);
  ImageName->setColor(sf::Color::Red);
  ImageName->setString(Image_list->currentFileName());
  font.loadFromFile("./conversation.ttf");
  ImageName->setFont(font);
}

int main(/*int argc, char *argv[]*/)
{
  srand(time(NULL));
  Settings::init("settings.json");
  Image_list.reset(new ImageList);

  if(!Image_list->isValid())
  {
    std::cerr << "Target directory must contains at least two png images.";
    return EXIT_FAILURE;
  }

  pickRenderer();

  Window.reset(new sf::RenderWindow({sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height}, "", sf::Style::None));
  Window->setFramerateLimit(60);

  if(Settings::showFilename())
    createImageName();

  utils::time::Timer timer;
  const sf::Time next_change_time = sf::seconds(Settings::transitionSecs() + Settings::waitSecs());
  sf::Time total_elapsed_time;

  while(Window->isOpen())
  {
    const sf::Time elapsed_time {timer.restart()};

    total_elapsed_time += elapsed_time;
    if(total_elapsed_time >= next_change_time)
    {
      next();
      total_elapsed_time = sf::Time::Zero;
    }

    handleEvents();
    draw(elapsed_time);
  }

  return EXIT_SUCCESS;
}
