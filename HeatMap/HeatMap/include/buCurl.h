#pragma once
#include "buCommons.h"
#include "curl\curl.h"

namespace buHeatMapSDK {
	class buCurl
	{
	public:
		buCurl() = default;
		buCurl(std::string _url);
		~buCurl();

		/**
		 * @brief Method in charge of post information to http service.
		 */
		void
			post(std::string _url, std::string data);

		void
			get(std::string _url);

		static
			size_t
			WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
			((std::string*)userp)->append((char*)contents, size * nmemb);
			return size * nmemb;
		}

		static size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream)
		{
			size_t written = fwrite(ptr, size, nmemb, (FILE*)stream);
			return written;
		}

	public:
		CURLcode m_res;
		std::string  response_string;
	private:
		CURL* m_curl;
		std::string m_readBuffer;
		std::string m_url;
		std::string  header_string;
	};
}