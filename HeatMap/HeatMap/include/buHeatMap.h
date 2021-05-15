#pragma once
#include "buCommons.h"
#include <SFML/Graphics.hpp>
namespace buHeatMapSDK {
	class buHeatMap
	{
	public:
		buHeatMap() = default;
		~buHeatMap() = default;

		int 
		run(std::vector<sf::Vector3f> _positions);

		void 
		onCreate(std::vector<sf::Vector3f> _positions);

		void 
		onUpdate();
		
		void 
		onRender();
		
		void 
		onDestroy();
	private:
		sf::RenderWindow* m_window;// (sf::VideoMode(1080, 800), "Heat Map Detector");
		std::vector<sf::CircleShape> circle;
	};
}