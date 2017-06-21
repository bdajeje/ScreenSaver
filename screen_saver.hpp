#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include <memory>

#include <SFML/Graphics.hpp>

#include "events/eventsubscriber.hpp"
#include "image_list.hpp"
#include "renderers/texture_renderer.hpp"
#include "text.hpp"
#include "utils/timer.hpp"

class ScreenSaver final : public events::EventSubscriber
{
	public:

		ScreenSaver(const std::string& screenshot_filepath);

		void start();

	protected:

		void pickRenderer();
		TextureRenderer* createRenderer(const std::string& /*name*/);
		void draw(const sf::Time& elapsed_time);
		void handleEvents();
		void next();
//		void transitionStarted();

	protected:

		uint _screen_width;
		uint _screen_height;
		uint _transition_secs;
		uint _wait_secs;
		std::unique_ptr<ImageList> _image_list;
		sf::RenderWindow _window;
		utils::time::Timer _timer;
		sf::Event _event;
		sf::Time _next_change_time;
		sf::Time _total_elapsed_time;
		std::unique_ptr<Text> _image_name;
		std::unique_ptr<Text> _time_text;
		Text* _displayed_text {nullptr}; // Helper pointer to text to display (points either to _image_name, _time_text or nothing
		std::unique_ptr<TextureRenderer> _renderer;
		sf::Font _font;
		time_t _last_update_text_time;
};

#endif // SCREENSAVER_H
