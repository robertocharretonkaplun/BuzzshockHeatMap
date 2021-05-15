#include "buHeatMap.h"

namespace buHeatMapSDK {
  void buHeatMap::onCreate(std::vector<sf::Vector3f> _positions)
  {
    m_window = new sf::RenderWindow(sf::VideoMode(1080, 800), "Heat Map Detector");

    for (int i = 0; i < _positions.size(); i++) {
      sf::CircleShape s(100.f);
      s.setRadius(10.f);
      s.setPosition(_positions[i].x, _positions[i].y);
      s.setFillColor(sf::Color::Red);
      s.setOrigin(_positions[i].x / 2.f, _positions[i].y / 2.f);
      s.setOutlineThickness(1);
      s.setOutlineColor(sf::Color::Blue);
      circle.push_back(s);
    }
  }
  int buHeatMap::run(std::vector<sf::Vector3f> _positions)
  {
    onCreate(_positions);
    while (m_window->isOpen()) {
      sf::Event event;
      while (m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
          m_window->close();
      }
      onUpdate();
      onRender();
    }
    return 0;
  }

  void 
  buHeatMap::onUpdate() {
  }

  void buHeatMap::onRender() {
      m_window->clear();
      //window.draw(shape);
      for (auto cir : circle) {
        m_window->draw(cir);
      }
      m_window->display();
  }

  void buHeatMap::onDestroy() {
  }
}