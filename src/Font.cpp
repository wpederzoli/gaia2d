#include "Font.h"

Font::Font()
{
    m_texture = NULL;
    m_xPos = 0;
    m_yPos = 0;
    m_width = 0;
    m_heigth = 0;
};

Font::~Font(){};

void Font::setPosition(int x, int y)
{
    m_xPos = x;
    m_yPos = y;
};

bool Font::load(char const fontFile[], const char text[], int fontSize, Uint8 r, Uint8 g, Uint8 b, Uint8 a, Graphics* graphics)
{
    TTF_Font* font = TTF_OpenFont(fontFile, fontSize);
    if(font == NULL)
    {   
        printf("Failed to load font %s\n", TTF_GetError() );
        return false;
    }

    SDL_Color color = {r, g, b, a};
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    m_texture = SDL_CreateTextureFromSurface(graphics->getRenderer(), surface);

    SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_heigth);

    SDL_FreeSurface(surface);
    TTF_CloseFont(font);

    return true;
};

void Font::draw(Graphics* g)
{
    SDL_Rect dest = { m_xPos, m_yPos, m_width, m_heigth };
    SDL_RenderCopy(g->getRenderer(), m_texture, NULL, &dest);
};

void Font::free()
{
    SDL_DestroyTexture(m_texture);
    m_texture = NULL;
};