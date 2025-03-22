# Flappy Bird Clone in C (Console-Based)

A simple **Flappy Bird Clone** written in C, using ASCII graphics for a minimalistic game experience. This project demonstrates basic **game physics, event handling, and collision detection** without requiring any external graphics libraries.

## Features
- 🐦 **Simple ASCII Graphics** - Runs in the terminal.
- 🎮 **Basic Physics** - Gravity and jump mechanics.
- 🚧 **Procedural Pipes** - Randomly generated obstacles.
- 🎯 **Score Tracking** - Survive as long as possible!
- 🔥 **No External Libraries Required** - Works with pure C.

## Demo
```
----------------------------------------
|                                      |
|    @                                 |
|                                      |
|                                      |
|         |  |                         |
|         |  |                         |
|                                      |
----------------------------------------
Score: 10
```

## Installation & Compilation
### Windows (MinGW)
1. Clone the repository:
   ```bash
   git clone https://github.com/AqibTayyab/Flappy-Bird-Clone-in-C-Console-Based-.git
   cd Flappy-Bird-Clone-in-C-Console-Based
   ```
2. Compile the game:
   ```bash
   gcc main.c -o flappy_bird.exe
   ```
3. Run the game:
   ```bash
   flappy_bird.exe
   ```

### Linux/macOS (Alternative)
Modify `_kbhit()` and `_getch()` with appropriate functions.

## How to Play
- **Press SPACE or W** to jump.
- **Avoid hitting pipes** or the ground.
- **Survive as long as possible** to increase your score.

## Future Improvements
✅ **Add Colors** - Use ANSI escape codes.
✅ **Better Graphics** - Use OpenGL or Raylib.
✅ **Sound Effects** - Add Beep() or external audio.

## Contributing
Pull requests are welcome! If you have suggestions, create an issue or fork the project.

## License
This project is open-source and available under the **MIT License**.

---
🚀 **Happy Coding & Flapping!**

