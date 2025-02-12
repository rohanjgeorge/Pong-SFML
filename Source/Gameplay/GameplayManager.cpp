#pragma once
#include "../../Header/Gameplay/GameplayManager.h"

namespace Gameplay
{
	GameplayManager::GameplayManager(EventManager* manager)
	{
		time_service->initialize();
		event_manager = manager;
	}

	void GameplayManager::updatePlayerScore()
	{
		if (ball->isLeftCollisionOccurred())
		{
			ui_service->incrementPlayer2Score();
			ball->updateLeftCollisionState(false);
			resetPlayer();
		}

		if (ball->isRightCollisionOccurred())
		{
			ui_service->incrementPlayer1Score();
			ball->updateRightCollisionState(false);
			resetPlayer();
		}
	}

	void GameplayManager::resetPlayer()
	{
		player1->reset(player1_position_x, player1_position_y);
		player2->reset(player2_postion_x, player2_postion_y);
	}

	void GameplayManager::update()
	{
		time_service->update();
		player1->update(event_manager->isKeyPressed(Keyboard::W), event_manager->isKeyPressed(Keyboard::S), time_service);
		player2->update(event_manager->isKeyPressed(Keyboard::Up), event_manager->isKeyPressed(Keyboard::Down), time_service);
		ball->update(player1, player2, time_service);

		updatePlayerScore();
		ui_service->update();
	}

	void GameplayManager::render(RenderWindow* game_window)
	{
		boundary->render(game_window);
		ball->render(game_window);
		player1->render(game_window);
		player2->render(game_window);
		ui_service->render(game_window);
	}
}