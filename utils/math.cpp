#include "math.hpp"

#include <stdlib.h>

namespace utils {

int random(int min, int max)
{
  return rand() % (max - min) + min;
}

}
