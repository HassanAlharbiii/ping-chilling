#include <raylib.h>
int main(void)
{
  const int screenHight = 450;
  const int screenWidth = 800;
  InitWindow(screenWidth, screenHight, "Window");
  SetTargetFPS(60);
  int player1Y = 50;
  int Player2Y = 50;
  int ballX = screenWidth / 4;
  int ballY = screenHight / 4;
  const int speed = 3;
  const float radius = 20;
  bool toright = true;
  bool toUp = true;
  while (!WindowShouldClose())
  {
    Vector2 ball_center = {ballX, ballY};
    Rectangle Player1_paddelrec = {0, player1Y, 15, 120};
    if (CheckCollisionCircleRec(ball_center, radius, Player1_paddelrec))
    {
      toright = true;

    } // CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);
    Rectangle Player2_paddelrec = {780, Player2Y, 15, 80};
    if (CheckCollisionCircleRec(ball_center, radius, Player2_paddelrec))
    {
      toright = false;

    } // CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);
    if (ballY == screenHight - radius)
    {
      toUp = true;
    }
    if (ballY == 0 + radius)
    {
      toUp = false;
    }

    if (toUp)
    {
      ballY -= 1;
    }
    else
    {
      ballY += 1;
    }

    if (ballX == screenWidth - radius)
    {
      toright = false;
    }
    if (ballX == 0 + radius)
    {
      toright = true;
    }

    if (toright)
    {
      ballX += 1;
    }
    else
    {
      ballX -= 1;
    }

    if (IsKeyDown(KEY_W))
    {
      player1Y -= speed;
    }
    if (IsKeyDown(KEY_E))
    {
      player1Y += speed;
    }
    if (IsKeyDown(KEY_W))
    {
      Player2Y -= speed;
    }
    if (IsKeyDown(KEY_E))
    {
      Player2Y += speed;
    }
    BeginDrawing();

    ClearBackground(BLACK);
    DrawCircle(ballX, ballY, radius, WHITE);
    DrawRectangle(0, player1Y, 15, 120, WHITE);
    DrawRectangle(780, Player2Y, 15, 80, WHITE);

    EndDrawing();
  }
}