#include "screen_saver.hpp"

#include "renderers/basic_fade_renderer.hpp"
#include "utils/settings.hpp"

ScreenSaver::ScreenSaver(const std::shared_ptr<ImageList>& image_list)
	: _screen_width (sf::VideoMode::getDesktopMode().width)
	, _screen_height (sf::VideoMode::getDesktopMode().height)
	, _transition_secs (Settings::transitionSecs())
	, _wait_secs (Settings::waitSecs())
	, _image_list (image_list)
	, _window {{_screen_width, _screen_height}, "", sf::Style::None}
	, _next_change_time (sf::seconds(_transition_secs + _wait_secs))
	, _show_filename {Settings::showFilename()}
	, _show_current_time {Settings::showCurrentTime()}
{
	_window.setFramerateLimit(30);

	pickRenderer();

	if(_show_filename || _show_current_time)
	{
		_font.loadFromFile("./conversation.ttf");

		if(_show_filename)
		{
		  _image_name.setCharacterSize(45);
		  _image_name.setColor(sf::Color::Red);
		  _image_name.setFont(_font);
		}

		if(_show_current_time)
		{
			_time_text.setCharacterSize(35);
			_time_text.setColor(sf::Color::Red);
			_time_text.setFont(_font);
		}
	}
}

TextureRenderer* ScreenSaver::createRenderer(const std::string& /*name*/)
{
  // if(name == "Rain")
  //   return new RainRenderer(image_list->current(), image_list->next(), screen_width, screen_height);
  // else
	return new BasicFadeRenderer(_image_list->current(), _image_list->next(), _screen_width, _screen_height);
}

void ScreenSaver::pickRenderer()
{
  const auto& renderers = Settings::renderers();
  const int random_offset = rand() % renderers.size();
  _renderer.reset(createRenderer(renderers[random_offset]));
}

void ScreenSaver::start()
{
	while(_window.isOpen())
	{
	  const sf::Time elapsed_time {_timer.restart()};
	  _total_elapsed_time += elapsed_time;

	  if(_total_elapsed_time >= _next_change_time)
		next();

	  handleEvents();
	  draw(elapsed_time);
	}
}

void ScreenSaver::next()
{
  _total_elapsed_time = sf::Time::Zero;

  _image_list->loadNext();
  pickRenderer();

  if(_show_filename)
	_image_name.setString(_image_list->currentFileName());
}

void ScreenSaver::handleEvents()
{
  while(_window.pollEvent(_event))
  {
	if(_event.type == sf::Event::KeyPressed)
	{
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		next();
	  else
		_window.close();

	  return;
	}
  }
}

void ScreenSaver::draw(const sf::Time& elapsed_time)
{
  _window.clear(sf::Color::Black);

  if(_renderer->update(elapsed_time, _window))
  {
	if(_show_filename)
	  _window.draw(_image_name);

	_window.display();
  }
}