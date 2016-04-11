#ifndef __MAIN_CLASS__
#define __MAIN_CLASS__

#include <SFML/Graphics.hpp>

class Main
{
	public:
		Main();
	private:
		void run();
		void exit();
		void tick();
		void render();
		bool running = true;
		int const FRAME_RATE = 20;
};

#endif
