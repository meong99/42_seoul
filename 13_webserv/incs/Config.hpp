#ifndef CONFIG_HPP
# define CONFIG_HPP

#include <string>
#include <fcntl.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <set>

#include "Server.hpp"
#include "Location.hpp"
#include "Libft.hpp"
#include "Webserv.hpp"

class Server;
class Webserv;

class Config 
{
	private:
		Config(const Config &other);

		Webserv*							m_webserv;
		static Config*						m_config;
		std::map<std::string, Server>		m_server_map;
		std::map<std::string, std::string>	m_mime_typeMap;
		std::map<std::string, std::string>	m_status_codeMap;

	public:
		static const int					decodeMimeBase64[256];

		Config();
		virtual ~Config();
		Config&	operator=(const Config &other);

		static Config*	get_m_config();
		void			parsingConfig(std::string path);

		//get
		Webserv*							get_m_webserv();
		std::map<std::string, Server>&		get_m_server_map();
		std::map<std::string, std::string>&	get_m_mime_typeMap();
		std::map<std::string, std::string>&	get_m_status_codeMap();
		Server*								get_last_server();

		//set
		void	set_m_webserv(Webserv* webserv);

		//is
		bool	isKeyword(std::string keyword);

		//add
		// void addServerMap(std::string ipPort, Server Server);
};

#endif