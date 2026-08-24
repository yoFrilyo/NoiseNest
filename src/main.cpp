#include <iostream>
#include <string>
#include <sys/socket.h>
#include <sys/un.h>
#include <cstring>
#include <CLI/CLI.hpp>

bool send_command(const std::string& cmd);
void usage();



int main(int argc, char* argv[]) {
    CLI::App app{"noisenest"};

    // -- daemon lifecycle --
    auto start = app.add_subcommand("start", "start the noisenest daemon");
    start->callback([]() {
        std::cout << "starting noisenest daemon\n";
        // todo: spawn daemon process (handle logging somewhere else)
    });

    auto stop = app.add_subcommand("stop", "stop the noisenest daemon");
    stop->callback([]() {
        std::cout << "stopping damon\n";
        send_command("quit");
    });

    auto status = app.add_subcommand("status", "check daemon status");
    status->callback([]() {
            std::cout << "checking daemon status\n";
            send_command("status");
    });
 
    // -- audio options --
    auto play = app.add_subcommand("play", "play a soundbite");
    std::string soundbite_path;
    std::string soundbite_name;
    bool output_flag = false;
    bool toggle_stop = false;
    bool toggle_pause = false;
    bool loop = false;
    float volume = 0.5;
    
    play->add_option("path", soundbite_path, "path of sound file to play")->required();
    play->add_option("--name", soundbite_name, "name of the soundbite to play");
    play->add_flag("--output", output_flag, "also play to speakers")->needs("--name");
    play->add_flag("--toggle-stop", toggle_stop, "stop if already playing")->needs("--name");
    play->add_flag("--toggle-pause", toggle_pause, "pause if already playing/resume if paused")->needs("--name");
    play->add_flag("--loop", loop, "loop sound");
    play->add_option("--volume", volume, "volume level (0.0-1.0)");

    play->callback([&]() {
        std::string cmd = "play " + soundbite_path;
        cmd += " --name " + soundbite_name;
        if (output_flag) cmd += " --output";
        if (toggle_stop) cmd += " --toggle-stop";
        if (toggle_pause) cmd += " --toggle-pause";
        if (loop) cmd += " --loop";
        cmd += " --volume " + std::to_string(volume);
        send_command(cmd);
    });


    auto audio_stop = app.add_subcommand("audio-stop", "stop all sounds")->excludes(start);
    audio_stop->callback([] () {
        send_command("audio_stop");
    });

    CLI11_PARSE(app, argc, argv);
    return 0;
}



bool send_command(const std::string& cmd) {
    // todo:

    std::cout << cmd;
    return true;
}
