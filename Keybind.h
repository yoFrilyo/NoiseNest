// Keybind.h



#ifndef KEYBIND_H
#define KEYBIND_H



#include <unordered_set>
#include <SDL2/SDL_keycode.h>
#include <string>
#include <sstream>



class Keybind
{
    private:
    std::unordered_set<SDL_KeyCode> keycombo;

    public:
    Keybind(const std::string& str);
};
#endif