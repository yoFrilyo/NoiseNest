// SoundBite.h
// By Frilyo and Augie!

#ifndef SOUNDBITE_H
#define SOUNDBITE_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>



class SoundBite
{
    private:
        std::string name;
        std::string fileName;
        std::vector<SDL_Scancode> keyBind;
    public:
        bool play();
        bool changeName(std::string NAME);
        bool changeFile(std::string FILENAME);
        bool changeKeyBind(std::vector<SDL_Scancode> KEYBIND);

        SoundBite(std::string NAME, std::string FILENAME, std::vector<SDL_Scancode> KEYBIND);
        //~SoundBite();
};

#endif