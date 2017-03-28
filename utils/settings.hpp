#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <memory>

#include "utils/json.hpp"

class Settings final
{
  public:

    static void init(const std::string& filepath);
    static const std::string folder() { return _instance->_folder; }

  private:

    Settings(const std::string& filepath);

  private:

    std::string _folder;
    static std::unique_ptr<Settings> _instance;
};

#endif // SETTINGS_HPP