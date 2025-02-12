#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

namespace UI
{
    class UIService
    {
    private:

        Font font;
        Text left_score_text;
        Text right_score_text;

        string texture_path = "Assets/Fonts/Aloevera-OVoWO.ttf";

        int font_size = 40;
        Color font_color = Color::White;
        string initial_string = "00";

        float left_score_postion_x = 570.0f;
        float left_score_postion_y = 30.0f;

        float right_score_position_x = 670.0f;
        float right_score_position_y = 30.0f;

        int player1_score = 0;
        int player2_score = 0;

        string formatScore(int score);

        void loadFontTexture();
        void createLeftScoreText();
        void createRightScoreText();

    public:

        UIService();

        void incrementPlayer1Score();
        void incrementPlayer2Score();

        void update();
        void render(RenderWindow* game_window);
    };
}