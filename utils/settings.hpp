#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <memory>

#include "utils/json.hpp"

class Settings final
{
  public:

    static void init(const std::string& filepath);
    static const std::string folder() { return _instance->_folder; }
    static uint transitionSecs() { return _instance->_transition_duration; }
    static uint waitSecs() { return _instance->_wait_duration; }

  private:

    Settings(const std::string& filepath);

  private:

    std::string _folder;
    uint _transition_duration;
    uint _wait_duration;
    static std::unique_ptr<Settings> _instance;
};

#endif // SETTINGS_HPP
