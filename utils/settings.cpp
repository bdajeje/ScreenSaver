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
}
