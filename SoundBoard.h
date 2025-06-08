// SoundBoard.h



#ifndef SOUNDBOARD_H
#define SOUNDBOARD_H



#include "SoundBite.h"
#include <string>
#include <map>
#include <unordered_map>
#include <SDL2/SDL.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;



struct KeySetHash {
    size_t operator()(const std::unordered_set<SDL_Keycode>& keys) const {
        size_t hash = 0;
        for (auto& key : keys) {
            hash ^= std::hash<int>{}(key) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

struct KeySetEqual {
    bool operator()(const std::unordered_set<SDL_Keycode>& a, const std::unordered_set<SDL_Keycode>& b) const {
        return a == b;
    }
};



class SoundBoard
{
    private:
    std::unordered_map<std::unordered_set<SDL_Keycode>, SoundBite, KeySetHash, KeySetEqual> soundBites_byKey;
    std::map<std::string, SoundBite> soundBites_byName;

    SoundBoard(const std::unordered_map<std::unordered_set<SDL_Keycode>, SoundBite, KeySetHash, KeySetEqual>& sounds_byKey,
        const std::map<std::string, SoundBite>& sounds_byName);

    public:

    static SoundBoard fromJson(const std::string& filepath);
    const SoundBite& get(const std::unordered_set<SDL_Keycode>& keybinds) const;
    const SoundBite& get(const std::string& name) const;
};
#endif