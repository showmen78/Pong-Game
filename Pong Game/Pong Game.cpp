#include "raylib.h"

// Screen dimensions
const int screenWidth = 800;
const int screenHeight = 600;

// Paddle dimensions
const int paddleWidth = 10;
const int paddleHeight = 100;
const int paddleSpeed = 500; // Pixels per second

// Ball dimensions and speed
const int ballSize = 10;
const float ballSpeed = 300.0f;
const Color background_color = {40,140,83,0.8};

// Function prototypes
void ResetBall(Vector2& ballPosition, Vector2& ballVelocity);

int main() {
    // Initialize the window
    InitWindow(screenWidth, screenHeight, "Pong Game - By SHOWMEN DEY");
    SetTargetFPS(60);

    // Initialize paddle positions
    Rectangle leftPaddle = { 50, screenHeight / 2 - paddleHeight / 2, paddleWidth, paddleHeight };
    Rectangle rightPaddle = { screenWidth - 50 - paddleWidth, screenHeight / 2 - paddleHeight / 2, paddleWidth, paddleHeight };

    // Initialize ball position and velocity
    Vector2 ballPosition = { screenWidth / 2, screenHeight / 2 };
    Vector2 ballVelocity = { ballSpeed, ballSpeed / 2 }; // Adjust velocity for angle

    // Scores
    int leftScore = 0;
    int rightScore = 0;

    // Main game loop
    while (!WindowShouldClose()) {
        // Delta time for consistent movement
        float deltaTime = GetFrameTime();

        // Paddle controls
        if (IsKeyDown(KEY_W) && leftPaddle.y > 0) {
            leftPaddle.y -= paddleSpeed * deltaTime;
        }
        if (IsKeyDown(KEY_S) && leftPaddle.y < screenHeight - paddleHeight) {
            leftPaddle.y += paddleSpeed * deltaTime;
        }
        if (IsKeyDown(KEY_UP) && rightPaddle.y > 0) {
            rightPaddle.y -= paddleSpeed * deltaTime;
        }
        if (IsKeyDown(KEY_DOWN) && rightPaddle.y < screenHeight - paddleHeight) {
            rightPaddle.y += paddleSpeed * deltaTime;
        }

        // Ball movement
        ballPosition.x += ballVelocity.x * deltaTime;
        ballPosition.y += ballVelocity.y * deltaTime;

        // Ball collision with walls
        if (ballPosition.y <= 0 || ballPosition.y >= screenHeight - ballSize) {
            ballVelocity.y *= -1; // Reverse Y direction
        }

        // Ball collision with paddles
        if (CheckCollisionCircleRec(ballPosition, ballSize / 2, leftPaddle) && ballVelocity.x < 0) {
            ballVelocity.x *= -1.1f; // Reverse X direction and increase speed
        }
        if (CheckCollisionCircleRec(ballPosition, ballSize / 2, rightPaddle) && ballVelocity.x > 0) {
            ballVelocity.x *= -1.1f; // Reverse X direction and increase speed
        }

        // Scoring
        if (ballPosition.x <= 0) {
            rightScore++;
            ResetBall(ballPosition, ballVelocity);
        }
        if (ballPosition.x >= screenWidth) {
            leftScore++;
            ResetBall(ballPosition, ballVelocity);
        }

        // Drawing
        BeginDrawing();
        ClearBackground(background_color);

        // Draw paddles
        DrawRectangleRec(leftPaddle, WHITE);
        DrawRectangleRec(rightPaddle, WHITE);

        // Draw ball
        DrawCircleV(ballPosition, ballSize / 2, WHITE);

        // Draw scores
        DrawText(TextFormat("%d", leftScore), screenWidth / 4, 20, 40, WHITE);
        DrawText(TextFormat("%d", rightScore), 3 * screenWidth / 4, 20, 40, WHITE);

        // Draw center line
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, GRAY);

        // Draw control hints
        DrawText("Player 1: Use W and S", 10, screenHeight - 50, 20, WHITE);
        DrawText("Player 2: Use UP and DOWN", screenWidth - 390, screenHeight - 50, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// Function to reset ball position and velocity
void ResetBall(Vector2& ballPosition, Vector2& ballVelocity) {
    ballPosition = { screenWidth / 2, screenHeight / 2 };
    ballVelocity = { ballSpeed * (GetRandomValue(0, 1) ? 1 : -1), ballSpeed / 2 * (GetRandomValue(0, 1) ? 1 : -1) };
}
