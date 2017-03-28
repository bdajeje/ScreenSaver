#ifndef IMAGELIST_HPP
#define IMAGELIST_HPP

#include <vector>

#include "SFML/Graphics/Texture.hpp"

class ImageList final
{
  public:

    ImageList();

    const sf::Texture& current() const noexcept;
    const sf::Texture& next() const noexcept;
    bool isValid() const noexcept { return _files.size() >= 2; }
    void loadNext();

  private:

    void getTexture(size_t offset, sf::Texture& texture);    

  private:

    std::vector<std::string> _files;
    sf::Texture _current;
    sf::Texture _next;
    size_t _offset {0};
};

#endif // IMAGELIST_HPP
