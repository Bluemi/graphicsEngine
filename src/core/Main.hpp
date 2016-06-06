#ifndef __MAIN_CLASS__
#define __MAIN_CLASS__

#include <SFML/Window.hpp>

#include "Screen.hpp"
#include "GraphicsEngine.hpp"

class Main
{
	public:
		Main();
		~Main();
		void handleKeyPressEvent(const sf::Event&);
		void handleKeyReleaseEvent(const sf::Event&);
		void handleMouseMoveEvent(const sf::Event&);
		static Screen* getScreen();
	private:
		// functions
		void run();
		void exit();
		void tick();
		void render();
		void handleEvents();

		bool running;

		// members
		GraphicsEngine graphicsEngine;
		static Screen* screen;
		int const FRAME_RATE = 20;
};

#endif
