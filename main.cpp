// main.cpp
// By Frilyo and Augie!

#include <nlohmann/json.hpp>
#include <fstream>
#include "SoundBite.h"

const std::string SAVE_FILE_NAME = "SavedSounds.json";

nlohmann::json loadFile();
bool saveFile(nlohmann::json SAVEFILE);



int main()
{
    nlohmann::json data = loadFile();



    saveFile(filepath);
}



nlohmann::json loadFile()
{
    std::fstream file(SAVE_FILE_NAME);
    if (!file.is_open()){
        throw std::runtime_error("Failed to open file: " + SAVE_FILE_NAME)
    }

}



bool saveFile(nlohmann::json SAVEFILE)
{

}