// Keybind.cpp


#include "Keybind.h"



Keybind::Keybind(const std::string& str)
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, '+')) {
        SDL_KeyCode code = stringToSDLKeycode(token);
        keycombo.insert(code);
    }
}