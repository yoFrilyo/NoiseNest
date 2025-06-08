// main.cpp



#include <iostream>
#include <fstream>
#include <unordered_map>
#include <SDL2/SDL.h>
#include <nlohmann/json.hpp>
#include "SoundBite.h"

using json = nlohmann::json;

const std::string filepath = "";



std::unordered_map<SDL_Keycode, SoundBite> parseJson_ByKeyBind(const std::string& filepath);
std::map<std::string, SoundBite> parseJson_ByName(const std::string& filepath);



int main()
{
    std::unordered_map<SDL_Keycode, SoundBite> soundBoard = parseJson_ByKeyBind(filepath);
    std::map<std::string, SoundBite> soundBoard_byName = parseJson_ByName(filepath);


}



std::unordered_map<SDL_Keycode, SoundBite> parseJson_ByKeyBind(const std::string& filepath)
{

}



std::map<std::string, SoundBite> parseJson_ByName(const std::string& filepath)
{

}