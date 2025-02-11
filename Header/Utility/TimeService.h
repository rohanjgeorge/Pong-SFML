#pragma once
#include <chrono>
using namespace std;

namespace Utility
{
	class TimeService
	{
	private:
		chrono::time_point<chrono::steady_clock> previous_time;
		float delta_time;

		void updateDeltaTime();
		float calculateDeltaTime();
		void updatePreviousTime(); // Update previous_time to the current time

	public:

		void initialize();
		void update();
		float getDeltaTime();
	};
}