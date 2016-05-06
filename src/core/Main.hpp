#ifndef __MAIN_CLASS__
#define __MAIN_CLASS__

#include <SFML/Window.hpp>

#include "Screen.hpp"

class Main
{
	public:
		Main();
		~Main();
		void handleKeyPressEvent(const sf::Event&) const;
		void handleKeyReleaseEvent(const sf::Event&) const;
	private:
		// functions
		void run();
		void exit();
		void tick();
		void render();
		void handleEvents() const;

		bool running;

		// members
		Screen* screen;
		int const FRAME_RATE = 20;
};

#endif
