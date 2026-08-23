# Noisenest - PipeWire Virtual Soundboard Daemon

A C++ daemon that creates a virtual microphone input for playing sound effects on demand via CLI commands. Built for PipeWire audio systems, Noisenest allows you to inject audio into your microphone input stream and optionally play it to output as well.

## Project Structure

```
noisenest/
├── conf/
│   └── noisenest.toml       # Configuration and sound definitions
├── include/noisenest/
│   ├── core/                # Core audio and daemon logic headers
│   └── utils/               # Utility and helper headers
└── src/
    ├── main.cpp             # Entry point
    ├── cli/                 # CLI command parsing and handling
    ├── core/                # Core audio processing and PipeWire integration
    ├── daemon/              # Daemon lifecycle and IPC server
    └── utils/               # Configuration, logging, and utilities
```

### Directory Descriptions

**conf/** - Contains all configuration files in TOML format, including daemon settings, audio parameters, and sound definitions.

**include/noisenest/core/** - Public interfaces for the audio engine, soundboard, and PipeWire integration.

**include/noisenest/utils/** - Public interfaces for cross-cutting concerns like configuration management, logging, and CLI parsing.

**src/cli/** - Handles parsing and processing commands from the command line or IPC socket, converting user intent into audio operations.

**src/core/** - Implements low-level PipeWire integration, audio stream management, and sound playback logic.

**src/daemon/** - Manages daemon lifecycle, signal handling, and the IPC server that listens for incoming commands.

**src/utils/** - Implements configuration loading, logging, and utility functions that support the rest of the application.
