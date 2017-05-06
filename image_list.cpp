#include "image_list.hpp"

#include "utils/directory.hpp"
#include "utils/settings.hpp"

ImageList::ImageList(const std::string& folder, sf::Texture&& first)
{
  const bool random = Settings::isRandom();

  _files = utils::listFiles(folder, ".*\.png", !random);

  if(isValid())
  {
    if(random)
      std::random_shuffle( _files.begin(), _files.end() );

    _next = std::move(first);
//    loadNext();
  }
}

const sf::Texture* ImageList::current() const noexcept
{
  return &_current;
}

const sf::Texture* ImageList::next() const noexcept
{
  return &_next;
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
