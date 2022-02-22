#include "../incs/Server.hpp"

Server::Server()
{
	m_fd_type = FD_SERVER;
	m_port = -1;
}

Server::Server(const Server &other)
{
	m_fd = other.m_fd;
	m_fd_type = other.m_fd_type;
	m_ip = other.m_ip;
	m_port = other.m_port;
	m_server_name = other.m_server_name;
	m_locationMap.insert(other.m_locationMap.begin(), other.m_locationMap.end());

}
Server::~Server()
{

}

Server &Server::operator=(const Server &other)
{
	m_fd = other.m_fd;
	m_fd_type = other.m_fd_type;
	m_ip = other.m_ip;
	m_port = other.m_port;
	m_server_name = other.m_server_name;
	if (!m_locationMap.empty())
	{
		m_locationMap.clear();
	}
	m_locationMap.insert(other.m_locationMap.begin(), other.m_locationMap.end());
	return (*this);
}

void Server::set_m_server_name(std::string server_name)
{
	m_server_name = server_name;
}

void Server::set_m_ip(std::string ip)
{
	m_ip = ip;
}

void Server::set_m_port(std::string port)
{
	m_port = port;
}

const std::string &Server::get_m_server_name(void) const
{
	return (m_server_name);
}

const std::string &Server::get_m_ip(void) const
{
	return (m_ip);
}

const std::string &Server::get_m_port(void) const
{
	return (m_port);
}

std::map<std::string, Location> &Server::get_m_locationMap()
{
	return (m_locationMap);
}

Location& Server::get_last_location(void)
{
	std::map<std::string, Location>::iterator it = m_locationMap.end();
	it--;
	return (it->second);
}

std::ostream &operator<<(std::ostream &o, Server &server)
{
	o << "==========Server==========" << std::endl;
	o << "IP: " << server.get_m_ip() << std::endl;
	o << "Port: " << server.get_m_port() << std::endl;
	o << "Server_name: " << server.get_m_server_name() << std::endl;

	o << "----------Location----------" << std::endl;
	for (std::map<std::string, Location>::iterator iter = server.get_m_locationMap().begin(); iter != server.get_m_locationMap().end(); iter++)
	{

		o << "maxbody: " << iter->second.get_m_max_body_size() << std::endl;
		o << "returnNum: " << iter->second.get_m_return_num() << std::endl;
		o << "autoindex: " << iter->second.get_m_auto_index() << std::endl;
		o << "root: " << iter->second.get_m_root() << std::endl;
		o << "Uri: " << iter->second.get_m_uri() << std::endl;
		o << "authkey: " << iter->second.get_m_auth_key() << std::endl;
		o << "returnUrl: " << iter->second.get_m_return_url() << std::endl;


		o << "AllowMethods: ";
		for (std::vector<std::string>::iterator i = iter->second.get_m_allow_methods().begin(); i != iter->second.get_m_allow_methods().end(); i++)
		{
			o << *i << " ";
		}
		o << std::endl << "Indexs: ";
		for (std::vector<std::string>::iterator i = iter->second.get_m_indexs().begin(); i != iter->second.get_m_indexs().end(); i++)
		{
			o << *i << " ";
		}
		o << std::endl << "ErrorPages : ";
		for (std::map<int, std::string>::iterator i = iter->second.get_m_error_pages().begin(); i != iter->second.get_m_error_pages().end(); i++)
		{
			o << (i->first) << " "<< (i->second) << " ";
		}

		o << std::endl << "Cgis : ";
		for (std::map<std::string, std::string>::iterator i = iter->second.get_m_cgi().begin(); i != iter->second.get_m_cgi().end(); i++)
		{
			o << (i->first) << " "<< (i->second) << " ";
		}
		o << std::endl;
	}
	o << std::endl;

	return o;
}

Location	&Server::getPerfectLocation(std::string &uri)
{
	Location *ret = &(m_locationMap["/"]);
	std::string key = "";
	for (std::string::const_iterator iter = uri.begin(); iter != uri.end(); iter++)
	{
		key += *iter;
		if (*iter == '/')
		{
			if (m_locationMap.find(key) == m_locationMap.end())
				return (*ret);
			else
				ret = &(m_locationMap[key]);
		}
	}
	if ( *(--key.end()) != '/') // '/'로 끝나지 않았고
	{
		key += '/';
		if (m_locationMap.find(key) != m_locationMap.end())
		{
			uri = key;
			return (m_locationMap[key]);
		}
	}
	return (*ret);
}