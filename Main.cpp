#include <iostream>
#include <SFML/Graphics.hpp>
#include "Header/Core/GameWindowManager.h"


int main() {
    // Create our window manager instance
    Core::GameWindowManager gameWindowManager;

    // Initialize the window
    gameWindowManager.initialize();

    while (gameWindowManager.isGameRunning()) {
        gameWindowManager.render();
    }

    return 0;
}