2D Game prototype project

Welcome to my project! This project was built using SFML and Visual Studio 2022, and it’s ready to compile and run. 
Follow the instructions below to set up the project and start the game.

Welcome to my 2D RPG game project! Built using SFML and Visual Studio 2022, this prototype is ready to compile and run. Follow the instructions below to set up the project and start the game.
Requirements

   - Visual Studio 2022 (or compatible C++ compiler)
   - SFML (included in dependencies)
   - YAML-CPP (included in dependencies)

Setup

   - Clone the repository:

  -  bash

  -  git clone https://github.com/FelixAtn/RPG-prototype

  -  Download the dependencies:
        The dependencies/ folder includes all required libraries and DLL files.

  -  Copy DLLs:
        To run the game, copy all DLL files from dependencies/dlls/ to the src/ directory (where the game’s executable will be).

Building the Game

  -  Open the Solution:
        Open the .sln file in Visual Studio 2022.

 -   Build:
        Ensure your configuration is set to x64-[Debug or Release], and then build the project.

Running the Game

   - Run from Visual Studio:
        After building, you can run the game directly from Visual Studio.

   - Run from Executable:
        If running from the executable after building, make sure the required DLLs and files (found in src) are present in the same folder.

Project Structure

makefile

my_project/
├── src/                # Source code files
│   ├── Engine/         # Core engine components and systems
│   ├── Game/           # Game-specific files and logic
│   ├── Files/          # Game assets like images, audio, etc.
│   └── main.cpp        # Main entry point of the game
├── dependencies/
│   ├── include/        # Header include files
│   ├── lib/            # External library files
│   └── dlls/           # Required DLL files
└── my_project.sln      # Visual Studio solution file

Credits

   - SFML - for graphics, audio, and system handling.
   - YAML-CPP - for parsing configuration files.
