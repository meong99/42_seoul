#include "../incs/Config.hpp"

Config* Config::m_config = 0; // static 멤버 변수 초기화 

int const Config::decodeMimeBase64[256] = {
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* 00-0F */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* 10-1F */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,62,-1,-1,-1,63,  /* 20-2F */
    52,53,54,55,56,57,58,59,60,61,-1,-1,-1,-1,-1,-1,  /* 30-3F */
    -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,  /* 40-4F */
    15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,  /* 50-5F */
    -1,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,  /* 60-6F */
    41,42,43,44,45,46,47,48,49,50,51,-1,-1,-1,-1,-1,  /* 70-7F */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* 80-8F */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* 90-9F */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* A0-AF */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* B0-BF */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* C0-CF */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* D0-DF */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* E0-EF */
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1   /* F0-FF */
};

Config::Config()
{
	m_status_codeMap["100"] = "Continue";
	m_status_codeMap["101"] = "Switching Protocols";
	m_status_codeMap["200"] = "OK";
	m_status_codeMap["201"] = "Created";
	m_status_codeMap["202"] = "Accepted";
	m_status_codeMap["203"] = "Non-authoritative Information";
	m_status_codeMap["204"] = "No Content";
	m_status_codeMap["205"] = "Reset Content";
	m_status_codeMap["206"] = "Partial Content";
	m_status_codeMap["300"] = "Multiple Choices";
	m_status_codeMap["301"] = "Moved Permanently";
	m_status_codeMap["302"] = "Found";
	m_status_codeMap["303"] = "See Other";
	m_status_codeMap["304"] = "Not Modified";
	m_status_codeMap["305"] = "Use Proxy";
	m_status_codeMap["307"] = "Temporary Redirect";
	m_status_codeMap["400"] = "Bad Request";
	m_status_codeMap["401"] = "Unauthorized";
	m_status_codeMap["402"] = "Payment Required";
	m_status_codeMap["403"] = "Forbidden";
	m_status_codeMap["404"] = "Not found";
	m_status_codeMap["405"] = "Method Not Allowed";
	m_status_codeMap["406"] = "Not Acceptable";
	m_status_codeMap["407"] = "Proxy Authentication Required";
	m_status_codeMap["408"] = "Required Timeout";
	m_status_codeMap["409"] = "Conflict";
	m_status_codeMap["410"] = "Gone";
	m_status_codeMap["411"] = "Length Required";
	m_status_codeMap["412"] = "Precondition Failed";
	m_status_codeMap["413"] = "Request Entity Too Large";
	m_status_codeMap["414"] = "Request URI Too Long";
	m_status_codeMap["415"] = "Unsupported Media Type";
	m_status_codeMap["416"] = "Requested Range Not Satisfiable";
	m_status_codeMap["417"] = "Expectation Failed";
	m_status_codeMap["418"] = "IM_A_TEAPOT";
	m_status_codeMap["500"] = "Internal Server Error";
	m_status_codeMap["501"] = "Not Implemented";
	m_status_codeMap["502"] = "Bad Gateway";
	m_status_codeMap["503"] = "Service Unavailable";
	m_status_codeMap["504"] = "Gateway Timeout";
	m_status_codeMap["505"] = "HTTP Version Not Supported";
	m_mime_typeMap[".aac"] = "audio/aac";
	m_mime_typeMap[".abw"] = "application/x-abiword";
	m_mime_typeMap[".arc"] = "application/octet-stream";
	m_mime_typeMap[".avi"] = "video/x-msvideo";
	m_mime_typeMap[".azw"] = "application/vnd.amazon.ebook";
	m_mime_typeMap[".bin"] = "application/octet-stream";
	m_mime_typeMap[".bz"] = "application/x-bzip";
	m_mime_typeMap[".bz2"] = "application/x-bzip2";
	m_mime_typeMap[".csh"] = "application/x-csh";
	m_mime_typeMap[".css"] = "text/css";
	m_mime_typeMap[".csv"] = "text/csv";
	m_mime_typeMap[".doc"] = "application/msword";
	m_mime_typeMap[".epub"] = "application/epub+zip";
	m_mime_typeMap[".gif"] = "image/gif";
	m_mime_typeMap[".htm"] = "text/html";
	m_mime_typeMap[".html"] = "text/html";
	m_mime_typeMap[".ico"] = "image/x-icon";
	m_mime_typeMap[".ics"] = "text/calendar";
	m_mime_typeMap[".jar"] = "application/java-archive";
	m_mime_typeMap[".jpeg"] = "image/jpeg";
	m_mime_typeMap[".jpg"] = "image/jpeg";
	m_mime_typeMap[".js"] = "application/js";
	m_mime_typeMap[".json"] = "application/json";
	m_mime_typeMap[".mid"] = "audio/midi";
	m_mime_typeMap[".midi"] = "audio/midi";
	m_mime_typeMap[".mpeg"] = "video/mpeg";
	m_mime_typeMap[".mpkg"] = "application/vnd.apple.installer+xml";
	m_mime_typeMap[".odp"] = "application/vnd.oasis.opendocument.presentation";
	m_mime_typeMap[".ods"] = "application/vnd.oasis.opendocument.spreadsheet";
	m_mime_typeMap[".odt"] = "application/vnd.oasis.opendocument.text";
	m_mime_typeMap[".oga"] = "audio/ogg";
	m_mime_typeMap[".ogv"] = "video/ogg";
	m_mime_typeMap[".ogx"] = "application/ogg";
	m_mime_typeMap[".pdf"] = "application/pdf";
	m_mime_typeMap[".ppt"] = "application/vnd.ms-powerpoint";
	m_mime_typeMap[".rar"] = "application/x-rar-compressed";
	m_mime_typeMap[".rtf"] = "application/rtf";
	m_mime_typeMap[".sh"] = "application/x-sh";
	m_mime_typeMap[".svg"] = "image/svg+xml";
	m_mime_typeMap[".swf"] = "application/x-shockwave-flash";
	m_mime_typeMap[".tar"] = "application/x-tar";
	m_mime_typeMap[".tif"] = "image/tiff";
	m_mime_typeMap[".tiff"] = "image/tiff";
	m_mime_typeMap[".ttf"] = "application/x-font-ttf";
	m_mime_typeMap[".vsd"] = "application/vnd.visio";
	m_mime_typeMap[".wav"] = "audio/x-wav";
	m_mime_typeMap[".weba"] = "audio/webm";
	m_mime_typeMap[".webm"] = "video/webm";
	m_mime_typeMap[".webp"] = "image/webp";
	m_mime_typeMap[".woff"] = "application/x-font-woff";
	m_mime_typeMap[".xhtml"] = "application/xhtml+xml";
	m_mime_typeMap[".xls"] = "application/vnd.ms-excel";
	m_mime_typeMap[".xml"] = "application/xml";
	m_mime_typeMap[".xul"] = "application/vnd.mozilla.xul+xml";
	m_mime_typeMap[".zip"] = "application/zip";
	m_mime_typeMap[".3gp"] = "video/3gpp audio/3gpp";
	m_mime_typeMap[".3g2"] = "video/3gpp2 audio/3gpp2";
	m_mime_typeMap[".7z"] = "application/x-7z-compressed";
}

Config::~Config()
{
	delete m_config;
}

Config::Config(const Config &other)
{
	*this = other;
}

Config& Config::operator=(const Config & other)
{
	m_webserv = other.m_webserv;
	m_server_map = other.m_server_map;
	m_mime_typeMap = other.m_mime_typeMap;
	m_status_codeMap = other.m_status_codeMap;
	return *this;
}

Config* Config::get_m_config(void)
{
	if (m_config == NULL)
	{
		m_config = new Config();
	}
	return m_config;
}

Webserv* Config::get_m_webserv()
{
	return m_webserv;
}

std::map<std::string, Server> &Config::get_m_server_map()
{
	return m_server_map;
}

std::map<std::string, std::string> &Config::get_m_mime_typeMap()
{
	return m_mime_typeMap;
}

std::map<std::string, std::string> &Config::get_m_status_codeMap()
{
	return m_status_codeMap;
}

Server* Config::get_last_server(void)
{
	std::map<std::string, Server>::iterator it = m_server_map.end();
	it--;
	return &(it->second);
}


void Config::set_m_webserv(Webserv* webserv)
{
	m_webserv = webserv;
}

bool	Config::isKeyword(std::string keyword)
{
	if (keyword == "server" ||
		keyword == "listen" ||
		keyword == "server_name" ||
		keyword == "location" ||
		keyword == "error_page" ||
		keyword == "allow_methods" ||
		keyword == "root" ||
		keyword == "index" ||
		keyword == "upload_path" ||
		keyword == "auto_index" ||
		keyword == "request_max_body_size" ||
		keyword == "auth_key" ||
		keyword == "cgi_info" ||
		keyword == "return" ||
		keyword == "}" ||
		keyword == "{" )
		return (true);
	return (false);
}

void 	Config::parsingConfig(std::string path)
{
	std::ifstream output;
	std::string lines;
	std::string temp;
	std::vector<std::string> vinfos;
	Server *server;
	Location *location;

	output.open(path, std::ofstream::in);
	if (output.fail())
	{
		std::cerr << "ERROR" << std::endl;
		exit(1);
	}
	while (getline(output, temp))
	{
		lines += temp;
	}
	ft_split(lines, " \t}{", vinfos);
	for (std::vector<std::string>::const_iterator it = vinfos.begin(); it != vinfos.end(); it++)
	{
		if (*it == "server_name")
		{
			it++;
			std::string server_name = *it;
			it++;
			it++;
			std::string port = *it;
			it++;
			std::string ip = *it;
			std::string key = ip +":"+ port;
			if (get_m_server_map().find(key) != get_m_server_map().end())
			{
				throw "Duplicated Server Ip:Port";
			}
			get_m_server_map()[key].set_m_server_name(server_name);
			get_m_server_map()[key].set_m_ip(ip);
			get_m_server_map()[key].set_m_port(port);
		}
		if (*it == "location")
		{
			server = get_last_server();
			it++;
			std::string uri = *it;
			if (server->get_m_locationMap().find(uri) != server->get_m_locationMap().end())
			{
				throw "Duplicated Location Uri";
			}
			server->get_m_locationMap()[uri].set_m_uri(uri);
			location = &(server->get_m_locationMap()[uri]);
		}
		if (*it == "error_page")
		{
			it++;
			int ernum = std::atoi((*it).c_str());
			it++;
			location->get_m_error_pages()[ernum] = *it;
		}
		if (*it == "allow_methods")
		{
			it++;
			std::vector<std::string> gpd;
			gpd.push_back("GET");
			gpd.push_back("POST");
			gpd.push_back("DELETE");
			while (std::find(gpd.begin(), gpd.end(), *it) != gpd.end())
			{
				location->get_m_allow_methods().push_back(*it);
				it++;
			}
			it--;
		}
		if (*it == "root")
		{
			it++;
			location->set_m_root(*it);
		}
		if (*it == "index")
		{
			it++;
			while(!isKeyword(*it))
			{
				location->get_m_indexs().push_back(*it);
				it++;
			}
			it--;
		}
		if (*it == "auto_index")
		{
			it++;
			if (*it == "on")
				location->set_m_auto_index(true);
			else
				location->set_m_auto_index(false);
		}
		if (*it == "cgi_info")
		{
			it++;
			std::string cgikey = *it;
			it++;
			location->get_m_cgi()[cgikey] = *it;

		}
		if (*it == "auth_key")
		{
			it++;
			location->set_m_auth_key(*it);
		}
		if (*it == "return")
		{
			it++;
			location->set_m_return_num(std::atoi((*it).c_str()));
			it++;
			location->set_m_return_url(*it);
		}
		if (*it == "request_max_body_size")
		{
			it++;
			location->set_m_max_body_size(std::atoi((*it).c_str()));
		}


	}
	// for (std::map<std::string, Server>::iterator k = getServerMap().begin(); k != getServerMap().end(); k++)
	// {
	// 	std::cout << k->second;
	// }

	output.close();
}
