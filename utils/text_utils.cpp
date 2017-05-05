#include "text_utils.hpp"

namespace utils {

std::string minStr(std::string input, size_t min_size, char filler)
{
  if(input.length() >= min_size)
    return input;

  input.insert(0, min_size - input.length(), filler);
  return input;
}

}
