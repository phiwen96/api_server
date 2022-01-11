// server.cpp

import Server;
import Http;
#include <nlohmann/json.hpp>

using std::cout, std::endl, std::string;
// using namespace std;
using namespace nlohmann;


auto main (int, char **) -> int
{	
	// read a JSON file
	auto file_users = std::ifstream {"data/users.json"};
	auto users = json {};
	file_users >> users;

	auto callback = [&users] (string incoming) -> std::string
	{
		auto request = http_request::parse (incoming);

		if (not request) // Error in request, return bad call kind of resonse.
		{
			auto response = http_response 
			{
				.status_line = 
				{
					.version = 1.0, 
					.status_code = 400,
					.status_phrase = "Bad Request"
				}, 

				.headers = 
				{
					{"Server", "ph"}
				}
			};

			return to_string (response);
		}

		if (request -> request_line.url == "/login")
		{
			auto data = json::parse (request -> data);
			// cout << std::setw(4) << data << endl;
			// cout << std::setw(4) << users << endl;
			auto exists = false;
			// cout << data["username"] << endl;

			for (auto const& user : users)
			{
				if (user ["username"] == data ["username"])
				{
					if (user ["password"] == data ["password"])
					{
						
					} else 
					{
						
					}

				} else 
				{

				}
			}
				// cout << "::" << i.dump() << endl;
		} else 
		{
			cout << "what?" << endl;
			cout << request->request_line.url << endl;
			cout << request->request_line.url.size() << endl;
 		}
		
		return "hej";
	};

	api::serve ("8080", callback);
	return 0;
}

// "HTTP/1.1 200 OK\r\n"
// "Server: ph"
// "Content-Type: text/html; charset=UTF-8\r\n"
// "Content-Length: 200\r\n\r\n"

// 			   "<!DOCTYPE html>\r\n"
// 			   "<html><head><title>Testing</title></head>\r\n"
// 			   "<body><p>Testing</p></body><html>\r\n";

// GET / HTTP/1.1
// Host: 127.0.0.1:8080
// Upgrade-Insecure-Requests: 1
// Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
// User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/15.1 Safari/605.1.15
// Accept-Language: en-GB,en;q=0.9
// Accept-Encoding: gzip, deflate
// Connection: keep-alive