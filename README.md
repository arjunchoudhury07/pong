# Pong Game written in C

This is a simple implementation of the classic Pong game written in C using the Raylib library for graphics and input handling. The game is designed to run on various platforms with the help of Raylib's multi-platform support.

## Raylib Installation

To use Raylib in your own projects, you can follow the installation instructions provided in the [Raylib GitHub repository](https://github.com/raysan5/raylib).

#### Installation in Debian Based Distros (Eg: Ubuntu)

```bash
   sudo apt install raylib
```

#### Installation in Arch Based Distros

```bash
   sudo pacman -S raylib
```

## Getting Started

To compile and run the game, follow these steps:

1. **Clone the repository:**

   ```bash
   git clone https://github.com/arjunchoudhury07/pong.git
   ```

2. **Navigate to the directory:**

   ```bash
   cd pong
   ```

3. **Make the build script executable:**

   ```bash
   chmod +x build.sh
   ```

4. **Compile the game:**

   ```bash
   ./build.sh
   ```

5. **Run the game:**
   ```bash
   ./pong
   ```

## Gameplay

- Use the keyboard controls to move the paddle up and down.
- The objective is to hit the ball past the opponent's paddle.
- If a Player misses the ball Opponent scores a point.

## Controls

- **W Key:** Move left paddle up
- **S Key:** Move left paddle down
- **UP Key:** Move right paddle up
- **DOWN Key:** Move right paddle down

## Features

- Basic Pong game mechanics.
- Graphics and input handling using the Raylib library.

## Acknowledgments

- Inspired by the classic Pong game.
- Utilizes the Raylib library for graphics and input handling.
