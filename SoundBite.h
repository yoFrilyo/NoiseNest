// SoundBite.h
// By Frilyo and Augie!

#define SOUNDBITE_H
#ifndef SOUNDBITE_H



class SoundBite
{
    private:
        string name;
        string fileName;
        vector<SDL_Scancode> keyBind;
    public:
        bool play();
        bool changeName(string NAME);
        bool changeFile(string FILENAME);
        bool changeKeyBind(vector<SDL_Scancode> KEYBIND);

        SoundBite(string NAME, string FILENAME, &vector<SDL_Scancode> KEYBIND);
        SoundBite~();
};

#endif