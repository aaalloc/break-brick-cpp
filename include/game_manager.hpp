#pragma once
#include "brick_manager.hpp"
#include "entity/ball.hpp"
#include "entity/brick.hpp"
#include "entity/paddle.hpp"
#include "game.hpp"
#include <random>

class GameManager
{
  private:
    std::shared_ptr<Game> m_game;
    BrickManager m_brickManager;

    std::vector<std::shared_ptr<Brick>> generateBricks(const int rows, const int columns, const int width,
                                                       const int height, std::mt19937 gen);
    std::shared_ptr<Ball> generateBall(const float x, const float y, const int radius, float ball_speed);

  public:
    GameManager(int width, int height, float ball_speed = .5f, float paddle_speed = .65f, int lifes = 3)
    {
        init(width, height, ball_speed, paddle_speed, lifes);
    }
    void init(int width, int height, float ball_speed, float paddle_speed, int lifes);
    inline std::shared_ptr<Game> getGame() const { return m_game; }
};