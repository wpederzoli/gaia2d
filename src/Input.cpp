#include <stdio.h>
#include "Input.h"

void Input::init()
{
    const Uint8* keyboard = (Uint8*) SDL_GetKeyboardState(&this->numKeys);

    this->keys = new bool[this->numKeys];
    this->prevKeys = new bool[this->numKeys];

    //Initialize the keys as the keyboard keys and all prevKeys to false.
    for(int i = 0; i < this->numKeys; i++)
    {
        this->keys[i] = keyboard[i];
        this->prevKeys[i] = false;
    }

    SDL_GetMouseState(&this->mouseX, &this->mouseY);

    //Number of mouse keys is 3
    for(int i = 1; i <= 3; i++)
    {
        //Comparison by bit (binary)
        this->mouseKeys[i] = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(i);
        this->prevMouseKeys[i] = false;
    }
};

void Input::kill()
{
    delete[] this->keys;
    delete[] this->prevKeys;
};

void Input::update()
{
    const Uint8* keyboard = (Uint8*) SDL_GetKeyboardState(&this->numKeys);

    for(int i = 0; i < this->numKeys; i++)
    {
        this->prevKeys[i] = this->keys[i];
        this->keys[i] = keyboard[i];
    }

    SDL_GetMouseState(&this->mouseX, &this->mouseY);

    //Number of mouse keys is 3
    for(int i = 0; i < 3; i++)
    {
        this->prevMouseKeys[i] = this->mouseKeys[i];
        this->mouseKeys[i] = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(i);
    }
};

bool Input::keyDown(int key)
{
    if(key < 0 || key > this->numKeys)
        return false;

    return this->keys[key];
};

bool Input::keyHit(int key)
{
    if(key < 0 || key > this->numKeys)
        return false;

    return (this->keys[key] && !this->prevKeys[key]);
};

bool Input::keyUp(int key)
{
    if(key < 0 || key > this->numKeys)
        return false;

    return (this->prevKeys[key] && !this->keys[key]);
};

bool Input::mouseDown(int key)
{
    //Number of mouse keys is 3
    if(key < 0 || key > 3)
        return false;
    
    return this->mouseKeys[key];
};

bool Input::mouseHit(int key)
{
    //Number of mouse keys is 3
    if(key < 0 || key > 3)
        return false;
    
    return (this->mouseKeys[key] && !this->prevMouseKeys[key]);
};

bool Input::mouseUp(int key)
{
    //Number of mouse keys is 3
    if(key < 0 || key > 3)
        return false;
    
    return (this->prevKeys[key] && !this->mouseKeys[key]);
};

int Input::getMouseX()
{
    return this->mouseX;
};

int Input::getMouseY()
{
    return this->mouseY;
};

void Input::setMousePosition(int x, int y)
{
    SDL_WarpMouseGlobal(x, y);
};

void Input::hideCursor(bool hide)
{
    if(hide)
        SDL_ShowCursor(SDL_DISABLE);
    else
        SDL_ShowCursor(SDL_ENABLE);
};
