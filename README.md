# Maze-Odyssey

## Introduction

Maze-Odyssey is a 3D maze game developed using C and SDL2. Navigate through intricate labyrinths in this immersive first-person experience.

**[https://bragik.my.canva.site/yellow-white-photo-and-videocentric-error-page-website-error-page](landing page)

**[Link to Project Blog Article]** (not yet)

### Author

**Khalid Lazrag**
- LinkedIn: [https://www.linkedin.com/in/khalid-lazrag-91305423a/](https://www.linkedin.com/in/khalid-lazrag-91305423a/)

## Installation

To install and run Maze-Odyssey, follow these steps:

1. Clone the repository:
   ```
   git clone https://github.com/yourusername/Maze-Odyssey.git
   cd Maze-Odyssey
   ```

2. Ensure you have the necessary dependencies installed:
   - SDL2
   - SDL2_image

3. Compile the project using the provided Makefile:
   ```
   make
   ```

   Alternatively, you can compile manually with:
   ```
   gcc -Wall -Werror -Wextra -pedantic -o raycaster src/*.c -lSDL2 -lSDL2_image -lm
   ```

## Usage

After compilation, run the game with:

```
./Maze-Odyssey
```

Use the following controls to navigate the maze:
- W: Move forward
- S: Move backward
- A: Rotate camera left
- D: Rotate camera right
- M: enable/disable mini map
- ESC: Exit the game

## Contributing

contributions are welcomed.

## Related Projects

- [Wolfenstein 3D](https://github.com/id-Software/wolf3d) - One of the first 3D first-person shooter games, which uses similar raycasting techniques.