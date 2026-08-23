#include <iostream>
#include <string>
#include <sys/socket.h>
#include <sys/un.h>
#include <cstring>
#include <CLI/CLI.hpp>

bool send_command(const std::string& cmd);
void usage();



int main(int argc, char* argv[]) {
    CLI::App app{"NoiseNest"};

    // -- daemon lifecycle --
    auto start = app.add_subcommand("start", "Start the noisenest daemon");
    start->callback([]() {
        std::cout << "Starting noisenest daemon\n";
        // TODO: spawn daemon process (handle logging somewhere else)
    });

    auto stop = app.add_subcommand("stop", "Stop the noisenest daemon");
    stop->callback({}() {
        std::cout << "Stopping damon\n";
        send_command("QUIT");
    });

    auto status = app.add_subcommand("status", "Check daemon status");
    status->callback([]() {
            std::cout << "Checking daemon status\n";
            send_command("STATUS");
 
    // -- audio options --
    auto audio = app.add_subcommand("audio", "Audio controls");

    auto audio_trigger = app.add_subcommand("trigger", "trigger a soundbite");
    audio_trigger->add_option("soundbite", soundbite, "Soundbite to play")->required();
    audio_trigger->callback([&]() {
        send_command("Audio_play " + soundbite);
    });

    auto play = app.add_subcommand("play", "Play a soundbite");
    std::string soundbite_path;
    std::string soundbite_name;
    bool output_flag = false;
    float volume = 1.0;
    bool toggle = false;
    bool loop = false;
    bool pause = false;
    
    play->add_option("path", soundbite_path, "Path of sound file to play")->required();
    play->add_option("--name", soundbite_name, "Name of the soundbite to play");
    play->add_flag("--output", output_flag, "Also play to speakers")->needs(soundbite_name);
    play->add_flag("--toggle-stop", toggle_stop, "Stop if already playing")->needs(soundbite_name);
    play->add_flag("--toggle-pause", toggle_pause, "Pause if already playing/Resume if paused")->needs(soundbite_name);
    play->add_flag("--loop", loop, "Loop sound");
    play->add_option("--volume", volume, "Volume level (0.0-1.0)");

    play->callback([&]() {
        std::string cmd = "PLAY " soundbite_path;
        cmd += " --name" + std::to_string(soundbite_name);
        if (output_flag) cmd += " --output";
        if (toggle_stop) cmd += " --toggle-stop";
        if (toggle_pause) cmd += " --toggle-pause";
        if (loop) cmd += " --loop";
        cmd += " --volume" + std::to_string(volume);
        send_command(cmd);
    }


    auto audio_stop = app.add_subcommand("stop", "stop all sounds")->excludes(start);
    audio_stop->callback([] () {
        send_command("audio_stop");
    });
}
