# My 2D GAME PROTOTYPE [ In Progress ] 

Welcome to my 2D game prototype project! Built using **SFML** and **Visual Studio 2022**, this prototype is ready to compile and run. Follow the instructions below to set up the project and start the game.

## Presentation Video

[Watch the presentation video](https://youtu.be/SrC1APVdNLc?si=_UcgaW2pXezXLm9H)

## Requirements

- **Visual Studio 2022** (or compatible C++ compiler)
- **SFML** (included in `dependencies`)
- **YAML-CPP** (included in `dependencies`)

## Setup

1. **Clone the repository**:
   ```bash
   git clone https://github.com/FelixAtn/RPG-prototype
   ```

2. **Download the dependencies**:
   - The `dependencies/` folder includes all required libraries and DLL files.

3. **Copy DLLs**:
   - To run the game, copy all DLL files from `dependencies/dlls/` to the `src/` directory (where the game’s executable will be).

## Building the Game

1. **Open the Solution**:
   - Open the `.sln` file in Visual Studio 2022.

2. **Build**:
   - Ensure your configuration is set to `x64-[Debug or Release]`, and then build the project.

## Running the Game

1. **Run from Visual Studio**:
   - After building, you can run the game directly from Visual Studio.

2. **Run from Executable**:
   - If running from the executable after building, make sure the required DLLs and files (found in `src`) are present in the same folder.

## Project Structure

```
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
```

## Development Process & Learning Resources

1. **Books**
   - **Game Programming Patterns by Robert Nystrom:** Guidance on applying design patterns to create clean, scalable game code. [Book link](https://gameprogrammingpatterns.com/)
   - **C++ Primer by Stanley B. Lippman, Josée Lajoie, Barbara E. Moo:** A comprehensive introduction to C++ programming. [Book link](https://www.amazon.co.uk/C-Primer-Stanley-B-Lippman/dp/0321714113)

2. **Online Books/Resources**
   - **LearnCPP by Alex, Nascardriver, Cosmin James, and the community:** A great starting point for learning C++. [Online](https://www.learncpp.com/)
   - **CppReference:** A valuable reference for C++ programming. [Online](https://en.cppreference.com/w/)
   - **SFML Documentation:** Essential for handling windowing, graphics, input, and sound. [SFML Docs](https://www.sfml-dev.org/tutorials/2.6/)
   - **YAML-CPP Wiki:** Useful for parsing configuration files. [YAML-CPP Wiki](https://github.com/jbeder/yaml-cpp/wiki)

3. **Videos**
   - **The Cherno:** C++ game development tutorials on YouTube. [YouTube](https://www.youtube.com/@TheCherno)
   - **Abdul Bari:** Comprehensive C++ deep dive course on Udemy. [Udemy](https://www.udemy.com/course/cpp-deep-dive/?srsltid=AfmBOoox6aMVUNeUxx0F51jV-FCFi4pd5Y8KF5bRwrRhrSK6-alkIRoe&couponCode=LEARNNOWPLANS)
   - **3Blue1Brown:** "Essence of Linear Algebra" series on YouTube. [YouTube](https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab)
   - **Will Hess:** The ultimate guide for physics in game development. [YouTube](https://www.youtube.com/watch?v=3lBYVSplAuo&ab_channel=WillHess)
   - **Javidx9:** Essential mathematics for aspiring game developers. [YouTube](https://www.youtube.com/watch?v=DPfxjQ6sqrc&t=1995s&ab_channel=javidx9)

## Author

This project is developed and maintained by **Felix Atanasescu**, a passionate aspiring junior game developer with a focus on C++ and real-time game development.

- **LinkedIn**: [Felix Atanasescu](https://linkedin.com/in/felix-atanasescu)
- **GitHub**: [FelixAtn](https://github.com/FelixAtn)
- **Email**: [felix.att@protonmail.com](mailto:felix.att@protonmail.com)

## Credits & Acknowledgements

- **SFML**: For providing a simple and efficient multimedia library.
- **YAML-CPP**: For making configuration management easy and readable.
- **Game Programming Patterns by Robert Nystrom**: For providing inspiration and guidance on game architecture.
- **Assets**: Assets will be included in the final version of the project.
