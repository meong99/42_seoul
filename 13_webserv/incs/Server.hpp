#ifndef SERVER_HPP
# define SERVER_HPP

#include "FdBase.hpp"
#include "Location.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>

class Server : public FdBase
{
	private: 
		std::string						m_server_name;
		std::string						m_ip;
		std::string						m_port;
		std::map<std::string, Location>	m_locationMap;

	public:
		Server();
		Server(const Server &other);
		virtual ~Server();
		Server	&operator=(const Server &other);

		void	set_m_server_name(std::string server_name);
		void	set_m_ip(std::string ip);
		void	set_m_port(std::string port);

		const std::string				&get_m_server_name(void) const;
		const std::string				&get_m_ip(void) const;
		const std::string				&get_m_port(void) const;
		std::map<std::string, Location>	&get_m_locationMap();
		
		Location&	get_last_location(void);
		Location&	getPerfectLocation(std::string &uri);

		

};

std::ostream	&operator<<(std::ostream &o, Server &server);

#endif