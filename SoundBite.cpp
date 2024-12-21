// SoundBite.cpp
// By Frilyo and Augie!

#include "SoundBite.h"



bool SoundBite::play()
{
    return false;
}



bool SoundBite::changeName(std::string NAME)
{
    name = NAME;
    return true;
}



bool SoundBite::changeFile(std::string FILENAME)
{
    fileName = FILENAME;
    return true;
}



bool SoundBite::changeKeyBind(std::vector<SDL_Scancode> KEYBIND)
{
    keyBind = KEYBIND;
    return true;
}



SoundBite::SoundBite(std::string NAME, std::string FILENAME, std::vector<SDL_Scancode> KEYBIND)
{
    name = NAME;
    fileName = FILENAME;
    keyBind = KEYBIND;
}