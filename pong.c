#include <raylib.h>
#include <stdio.h>

typedef struct {
  int position;
  int height;
  int score;
} Player;

int main() {
  float paddle_speed = 0;
  Player player_left = {.position = 400, .height = 200, .score = 0},
         player_right = {.position = 600, .height = 200, .score = 0};
  float velocity_x = 500, velocity_y = 500, position_x = 20, position_y = 20;
  char player_left_score[4], player_right_score[4];
  bool isPaused = false;
  InitWindow(1920, 1080, "PONG");
  InitAudioDevice();

  Music game_music =
      LoadMusicStream("/home/jemo/code/c/pong/assets/music/game_music.mp3");
  PlayMusicStream(game_music);
  Sound paddle_hit =
      LoadSound("/home/jemo/code/c/pong/assets/music/paddle_hit.wav");
  Sound game_over =
      LoadSound("/home/jemo/code/c/pong/assets/music/game_over.wav");

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    UpdateMusicStream(game_music);
    int w = GetRenderWidth();
    int h = GetRenderHeight();
    float time = GetFrameTime();
    if (isPaused) {
      if (position_x > w / 2)
        position_y = player_right.position + player_left.height / 2;
      else
        position_y = player_left.position + player_left.height / 2;
    } else {
      position_y += velocity_y * time;
      position_x += velocity_x * time;
    }
    // printf("player_left score: %d \nplayer_right score  : %d\n",
    //        player_left.score, player_right.score);
    // printf("position_x: %f \nposition_y: %f\n", position_x, position_y);
    // printf("w - 40: %d \nposition_y: %f\n", w - 160, position_y);
    // printf("prpos: %d \nplusheight: %d\n\n", player_right.position,
    //        player_right.position + player_right.height);
    // if (position_x <= 0 || position_x >= w) {
    //   velocity_x *= -1;
    // }

    // checks for collision with Top anf Bottom and changs direction
    if (position_y <= 0 || position_y >= h) {
      velocity_y *= -1;
    }

    // Game Over
    if (position_x < 10) {
      isPaused = true;
      player_right.score++;
      position_x = 100;
      velocity_x = 0;
      velocity_y = 0;
      PlaySound(game_over);
      paddle_speed = 0;

    } else if (position_x >= w - 10) {
      isPaused = true;
      player_left.score++;
      position_x = w - 80;
      velocity_x = 0;
      velocity_y = 0;
      PlaySound(game_over);
      paddle_speed = 0;
    }

    if (IsKeyPressed(KEY_SPACE) && isPaused) {
      if (position_x > w / 2) {
        velocity_x = -500;
        velocity_y = 500;
      } else {
        velocity_x = 500;
        velocity_y = 500;
      }
      isPaused = false;
    }

    // Check for collision with the paddles
    if (position_y >= player_right.position &&
        position_y <= player_right.position + player_right.height &&
        position_x >= w - 60) {
      PlaySound(paddle_hit);
      velocity_x *= -1 * 1.1;
      paddle_speed += 1;
    } else if (position_y >= player_left.position &&
               position_y <= player_left.position + player_left.height &&
               position_x <= 60) {
      PlaySound(paddle_hit);
      velocity_x *= -1 * 1.1;
      paddle_speed += 0.1;
    }

    // Paddle Movement
    if (IsKeyDown(KEY_W) && player_left.position > 0) {
      player_left.position -= 20 + paddle_speed;
    } else if (IsKeyDown(KEY_S) && player_left.position < h - 200) {
      player_left.position += 20 + paddle_speed;
    }
    if (IsKeyDown(KEY_UP) && player_right.position > 0) {
      player_right.position -= 20 + paddle_speed;
    } else if (IsKeyDown(KEY_DOWN) && player_right.position < h - 200) {
      player_right.position += 20 + paddle_speed;
    }

    // Convert score from Integer to String
    sprintf(player_left_score, "%d", player_left.score);
    sprintf(player_right_score, "%d", player_right.score);

    BeginDrawing();
    ClearBackground(CLITERAL(Color){0x18, 0x18, 0x18, 0xFF});
    DrawCircle(position_x, position_y, 20, RED);
    DrawRectangle(20, player_left.position, 20, player_left.height, GREEN);
    DrawRectangle(w - 40, player_right.position, 20, player_right.height,

                  GREEN);
    DrawText(player_left_score, w * 0.25, 50, 80, WHITE);
    DrawText(player_right_score, w * 0.75, 50, 80, WHITE);

    if (isPaused) {
      DrawText("Press <SPACE> to Resume", w * 0.2, h / 2, 80, WHITE);
    }
    EndDrawing();
  }
  return 0;
}
