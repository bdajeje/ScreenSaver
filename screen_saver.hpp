#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include <memory>

#include <SFML/Graphics.hpp>

#include "image_list.hpp"
#include "renderers/texture_renderer.hpp"
#include "utils/timer.hpp"

class ScreenSaver final
{
	public:

		ScreenSaver(const std::shared_ptr<ImageList>& image_list);

		void start();

	protected:

		void pickRenderer();
		TextureRenderer* createRenderer(const std::string& /*name*/);
		void draw(const sf::Time& elapsed_time);
		void handleEvents();
		void next();

	protected:

		uint _screen_width;
		uint _screen_height;
		uint _transition_secs;
		uint _wait_secs;
		std::shared_ptr<ImageList> _image_list;
		sf::RenderWindow _window;
		utils::time::Timer _timer;
		sf::Text _image_name;
		sf::Text _time_text;
		sf::Event _event;
		sf::Font _font;
		sf::Time _next_change_time;
		sf::Time _total_elapsed_time;
		std::unique_ptr<TextureRenderer> _renderer;
		bool _show_filename;
		bool _show_current_time;
};

#endif // SCREENSAVER_H