#include <SFML/Graphics.hpp>
#include "buJsonParser.h"
#include "buCurl.h"
#include "buHeatMap.h"
// Json parser
buHeatMapSDK::buJsonParser m_parser;

buHeatMapSDK::buCurl m_curl;

buHeatMapSDK::buHeatMap HeatMap;

/**
 * @brief Main method
 */
int main() {
  // Get Json from elastic search petition
  m_curl.get("http://localhost:9200/mytutorialindex/_search?pretty");
  // Parse elastic sear json to string and get postions from server
  m_parser.parse(m_curl.response_string);
  // Temporal positions for debbuging purpouses 
  m_parser.m_positions.push_back(sf::Vector3f(20, 20, 0));
  m_parser.m_positions.push_back(sf::Vector3f(10, 50, 0));
  m_parser.m_positions.push_back(sf::Vector3f(50, 20, 0));
  m_parser.m_positions.push_back(sf::Vector3f(45, 15, 0));
  m_parser.m_positions.push_back(sf::Vector3f(450, 150, 0));
  m_parser.m_positions.push_back(sf::Vector3f(555, 50, 0));
  m_parser.m_positions.push_back(sf::Vector3f(600, 400, 0));
  

  return HeatMap.run(m_parser.m_positions);
}

