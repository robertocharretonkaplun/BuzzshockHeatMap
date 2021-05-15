#pragma once
#include "buCommons.h"
#include "rapidjson\document.h"
#include "rapidjson\writer.h"
#include "rapidjson\stringbuffer.h"
#include <SFML/Graphics.hpp>
namespace buHeatMapSDK {
	class buJsonParser
	{
	public:
		/**
		 * @brief Default Constructor
		 */
		buJsonParser();

		/**
		 * @brief Default Destructor
		 */
		~buJsonParser() = default;

		/**
		 * @brief Parse json into DOM
		 */
		void
		parse(std::string data);

		/**
		 * @brief Test method in charge of creating a Json string
		 */
		void
			writeIntoJson();

		/**
		 * @brief
		 */
		void
			openDoc();

		void
			writePositions(buVector3F _vec);

		void
			createBuf();


		std::string 
		getStringFromJson(std::string& jsStr,const std::string& strKey);
	private:
		const char* m_json;
		rapidjson::Document m_document;
		rapidjson::Document::AllocatorType allocator;
		rapidjson::Value s;
	public:
		std::string m_buffer;
		std::vector< sf::Vector3f> m_positions;
	};
}