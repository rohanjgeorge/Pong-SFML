#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Gameplay/Paddle.h"
#include "../../Header/Utility/TimeService.h"

using namespace sf;
using namespace std;
using namespace Utility;


namespace Gameplay
{
    enum class BallState
    {
        Idle,
        Moving
    };

    class Ball
    {
    private:
        Texture pong_ball_texture;
        Sprite pong_ball_sprite;

        string texture_path = "Assets/Textures/Ball.png";

        const float scale_x = 0.06f;
        const float scale_y = 0.06f;

        const float position_x = 615.0f;
        const float position_y = 335.0f;

        Vector2f velocity;   // Velocity vector for ball movement
        const float ball_speed = 5.0f;
        const float speed_multiplier = 100.0f;

        float delay_duration = 2.0f;
        BallState current_state = BallState::Idle; // Initialize the ball's state
        float elapsed_delay_time = 0.0f;

        const float top_boundary = 20.0f;
        const float bottom_boundary = 700.0f;
        const float left_boundary = 0.0f;
        const float right_boundary = 1280.0f;

        void loadTexture();
        void initializeVariables();
        void reset();
        void updateDelayTime(float deltaTime);

    public:

        Ball();

        void move(TimeService* timeService);

        void handleBoudaryCollision();
        void handlePaddleCollision(Paddle* player1, Paddle* player2);
        void handleOutofBoundCollision();

        void onCollision(Paddle* player1, Paddle* player2);
        void update(Paddle* player1, Paddle* player2, TimeService* timeService);
        void render(RenderWindow* game_window);
    };
}