#ifndef __MAIN_CLASS__
#define __MAIN_CLASS__

#include "Screen.hpp"

class Main
{
	public:
		Main();
		~Main();
	private:
		// functions
		void run();
		void exit();
		void tick();
		void render();
		bool running = true;

		// members
		Screen* screen;
		int const FRAME_RATE = 20;
};

#endif
