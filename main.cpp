// main.cpp
// By Frilyo and Augie!

#include <iostream>
#include <stdexcept>
#include "tinyxml2.h"
#include "SoundBite.h"

const std::string SAVE_FILE = "SavedSounds.xml";
const std::string SAVE_FOLDER = "SoundFolder";

void error(const std::string& FAILMESSAGE);
tinyxml2::XMLElement* loadFile(const std::string& SAVEFILE, tinyxml2::XMLDocument& doc);
bool saveFile(const std::string& SAVEFILE, tinyxml2::XMLDocument& doc);



int main()
{
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement* root = loadFile(SAVE_FILE, doc);



    saveFile(SAVE_FILE, doc);
}



tinyxml2::XMLElement* loadFile(const std::string& SAVEFILE, tinyxml2::XMLDocument& doc)
{
    // find SAVEFILE
    tinyxml2::XMLError eResult = doc.LoadFile(SAVEFILE.c_str());
    if (eResult != tinyxml2::XML_SUCCESS){
        std::cout << SAVEFILE << " not found.\nCreating file " << SAVEFILE << " ...\n";
        
        // create SAVEFILE
        tinyxml2::XMLDeclaration* decl = doc.NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
        doc.InsertFirstChild(decl);
        tinyxml2::XMLElement* newRoot = doc.NewElement("Root");
        doc.InsertEndChild(newRoot);
        eResult = doc.SaveFile(SAVEFILE.c_str());
        if (eResult != tinyxml2::XML_SUCCESS){
            error("Failed to create " + SAVEFILE);
        }
        std::cout << SAVEFILE << " created successfully.\n";
    }

    // get root element
    tinyxml2::XMLElement* root = doc.RootElement();
    if (!root){
        error("No root element found in the XML file.");
    }

    return root;
}



bool saveFile(const std::string& SAVEFILE, tinyxml2::XMLDocument& doc)
{
    tinyxml2::XMLError eResult = doc.SaveFile(SAVEFILE.c_str());
    if (eResult != tinyxml2::XML_SUCCESS){
        error("Could not save XML file.");
    }
    std::cout << "File saved successfully.\n";
    return true;
}



void error(const std::string& FAILMESSAGE)
{
    std::string newErrorMessage = "ERROR: " + FAILMESSAGE;
    std::cerr << newErrorMessage;
    throw std::runtime_error(newErrorMessage);
}