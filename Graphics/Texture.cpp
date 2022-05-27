#include "Texture.hpp"

Texture::Texture(Window& window, Surface& surface)
{
    texture = SDL_CreateTextureFromSurface(window.getRenderer(),surface.image);

}

void Texture::init(Window& window, Surface& surface)
{
    texture = SDL_CreateTextureFromSurface(window.getRenderer(), surface.image);
}
