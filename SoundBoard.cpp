// SoundBoard.cpp



#include "SoundBoard.h"



SoundBoard::SoundBoard(const std::unordered_map<std::unordered_set<SDL_Keycode>, SoundBite, KeySetHash, KeySetEqual>& sounds_byKey,
        const std::map<std::string, SoundBite>& sounds_byName)
{
    soundBites_byKey = sounds_byKey;
    soundBites_byName = sounds_byName;
}



SoundBoard SoundBoard::fromJson(const std::string& filepath)
{
    std::unordered_map<std::unordered_set<SDL_Keycode>, SoundBite, KeySetHash, KeySetEqual> sounds_byKey;
    std::map<std::string, SoundBite> sounds_byName;

    std::ifstream file(filepath);
    if (!file) {
        std::cerr << "Failed to open JSON file: " << filepath << std::endl;
        return SoundBoard(sounds_byKey, sounds_byName);
    }

    json j;
    file >> j;

    for (const auto& item : j) {
        std::string name = item.at("name").get<std::string>();
        std::string filepath = item.at("file").get<std::string>();

        std::unordered_set<SDL_Keycode> keybinds;
        for (const auto& keyStr : item.at("keybinds")) {
            SDL_Keycode key = stringToSDLKeycode(keyStr);
            if (key != SDLK_UNKNOWN) {
                keybinds.insert(key);
            } else {
                std::cerr << "Warning: Unkown key name \"" << keyStr << "\" in " << name << std::endl;
            }
        }

        SoundBite currentSoundBite(name, filepath, keybinds);
        sounds_byName[name] = currentSoundBite;
        sounds_byKey[keybinds] = currentSoundBite;
    }

    return SoundBoard(sounds_byKey, sounds_byName);
}



const SoundBite& SoundBoard::get(const std::unordered_set<SDL_Keycode>& keybinds) const
{

}



const SoundBite& SoundBoard::get(const std::string& name) const
{
    auto it = soundBites_byName.find(name);
    if (it != soundBites_byName.end()) {
        return it->second;
    } else {
        throw std::out_of_range("SoundBite not found for name: " + name);
    }
}



SDL_Keycode stringToSDLKeycode(const std::string& key) {
    SDL_Keycode kc = SDL_GetKeyFromName(key.c_str());
    return kc != SDLK_UNKNOWN ? kc : SDLK_UNKNOWN;
}