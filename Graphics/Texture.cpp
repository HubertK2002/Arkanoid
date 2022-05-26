#include "Texture.hpp"

Texture::Texture(Window& window, Surface& surface)
{
    texture = SDL_CreateTextureFromSurface(window.getRenderer(),surface.image);

}
