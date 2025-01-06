# Pong Game - By Showmen Dey

## Description
A classic **Pong** game implemented in C++ using the **raylib** library. This game offers an engaging two-player experience with dynamic ball behavior, intuitive controls, and a simple yet enjoyable gameplay loop.

---

## Installation and Setup

### Prerequisites

1. **Install raylib**:
   - You can download and install raylib from the official website: [raylib](https://www.raylib.com/).
   - Follow the instructions to install raylib for your platform (Windows, Linux, macOS).

2. **Install a C++ compiler**:
   - Ensure you have a C++ compiler installed. If you’re on Linux, you can install `g++`. On Windows, you can use MinGW or Visual Studio.
   

3. **How to Play**:
- Player 1: Use the W (up) and S (down) keys to control the left paddle.
- Player 2: Use the UP ARROW and DOWN ARROW keys to control the right paddle.
- Objective: Use your paddle to hit the ball and prevent it from passing your side of the screen. Try to get the ball past your opponent's paddle to score a point.

## Game Mechanics
**Ball Movement**:
- The ball starts at the center of the screen with an initial velocity.
The ball will bounce off the top and bottom walls, reversing its Y-direction on collision.
- The ball's direction and speed will change when it collides with a paddle. The ball's speed increases after each paddle collision.
Scoring:

- Player 1: Scores a point when the ball crosses the right side of the screen.
- Player 2: Scores a point when the ball crosses the left side of the screen.
After scoring, the ball resets to the center with a randomized direction.
Ball Collisions:

**Paddle Collision:**
- If the ball hits the paddle, the ball bounces off and speeds up.
Wall Collision: The ball bounces off the top and bottom walls.
Control Hints:

## Controls
```bash
Player 1:
W - Move the left paddle up.
S - Move the left paddle down.

Player 2:
UP ARROW - Move the right paddle up.
DOWN ARROW - Move the right paddle down.
```

## Features
**Two-Player Mode**:

- Compete with a friend for the highest score.
Dynamic Ball Speed:

- As the ball collides with the paddles, its speed increases, making the game progressively harder.
Minimalistic Design:

- Simple yet effective graphics, ideal for quick and fun gameplay.

## Built With
- raylib: A simple and easy-to-use library to help you learn video game programming.

## Author
**Showmen Dey**

## Acknowledgments
- raylib team: For creating an excellent framework for developing games in C++.
