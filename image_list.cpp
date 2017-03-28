#include "image_list.hpp"

#include "utils/settings.hpp"
#include "utils/directory.hpp"

ImageList::ImageList()
{
  const auto& folder = Settings::folder();
  _files = utils::listFiles(folder, ".*\.png", true);

  if(isValid())
  {
    getTexture(0, _next);
    loadNext();
  }
}

const sf::Texture& ImageList::current() const noexcept
{
  return _current;
}

const sf::Texture& ImageList::next() const noexcept
{
  return _next;
}

void ImageList::getTexture(size_t offset, sf::Texture& texture)
{
  if(offset >= _files.size())
    return;

  const auto& folder = Settings::folder();
  texture.loadFromFile(folder + _files.at(offset));
}

void ImageList::loadNext()
{
  _current = std::move(_next);

  _offset++;
  if(_offset >= _files.size())
    _offset = 0;

  getTexture(_offset, _next);
}
