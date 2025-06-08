// SoundBite.cpp



#include "SoundBite.h"

#include <sstream>



SoundBite::SoundBite(std::string name, std::string filepath, std::unordered_set<SDL_Keycode> keybinds)
    : name(name), filepath(filepath), keybinds(keybinds) {}



std::string& SoundBite::getName() {return name;}

std::string& SoundBite::getFilepath() {return filepath;}

std::unordered_set<SDL_Keycode>& SoundBite::getKeybinds() {return keybinds;}

std::string SoundBite::getKeybindsAsString()
{
    std::ostringstream oss;
    bool first = true;

    for (SDL_Keycode key : keybinds) {
        if (!first) {
            oss << ", ";
        } else {
            first = false;
        }

        const char* name = SDL_GetKeyName(key);
        oss << (name ? name : "UNKNOWN");
    }

    return oss.str();
}



bool SoundBite::setName(const std::string& NAME)
{
    if (NAME.empty()) return false;
    name = NAME;
    return true;
}



bool SoundBite::setFilepath(const std::string& FILEPATH)
{
    if (FILEPATH.empty()) return false;
    filepath = FILEPATH;
    return true;
}



bool SoundBite::setKeybinds(const std::unordered_set<SDL_Keycode>& KEYBINDS)
{
    if (KEYBINDS.empty()) return false;
    keybinds = KEYBINDS;
    return true;
}



bool SoundBite::play()
{

}