#include "settings.hpp"

#include "utils/file.hpp"

std::unique_ptr<Settings> Settings::_instance;

void Settings::init(const std::string& filepath)
{
  _instance.reset(new Settings(filepath));
}

Settings::Settings(const std::string& filepath)
{
  const json data = json::parse(files::read(filepath));

  _folder = data["folder"];
  _transition_duration = data["transition_duration"];
  _wait_duration = data["wait_duration"];
  _random = data["random"];
  _show_filename = data["show_filename"];
  _scale = data["scale_up"];
  _show_current_time = data["show_current_time"];
  _screen_width = data["screen_width"];
  _screen_height = data["screen_height"];

  const auto& renderer_data = data["renderers"];
  _renderers.reserve(renderer_data.size());
  for(const auto& renderer : renderer_data)
	_renderers.push_back(renderer);
}
