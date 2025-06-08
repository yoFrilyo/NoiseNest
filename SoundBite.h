// Sounbite.h



#ifndef SOUNDBITE_H
#define SOUNDBITE_H



#include <string>
#include <SDL2/SDL.h>
#include <unordered_set>



class SoundBite
{
    private:
    std::string name;
    std::string filepath;
    std::unordered_set<SDL_Keycode> keybinds;

    public:
    SoundBite(std::string name, std::string filepath, std::unordered_set<SDL_Keycode> keybind);

    std::string& getName();
    std::string& getFilepath();
    std::unordered_set<SDL_Keycode>& getKeybinds();
    std::string getKeybindsAsString();

    bool setName(const std::string& NAME);
    bool setFilepath(const std::string& FILEPATH);
    bool setKeybinds(const std::unordered_set<SDL_Keycode>& KEYBINDS);

    bool play();
};
#endif