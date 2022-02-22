#ifndef REQUEST_HPP
# define REQUEST_HPP

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

#include "Libft.hpp"

class Client;
class Location;

typedef enum t_req_status
{
	HEADER_PARSING, 
	BODY_PARSING,
	CHUNKED,
	CHUNKED_BODY,
	CONTENT_BODY
} 			e_req_status;

class Request 
{
	private:
		std::string	m_origin;
		std::string	m_body;

		std::string							m_method;
		std::string							m_reqlocation;
		std::string							m_httpver;
		std::map<std::string, std::string>	m_headersMap;

		e_req_status	m_request_status;

		Client*	m_client;
		size_t	m_remain_body_value;	
		int	base64_decode(const char * text, char * dst, int numBytes);

	public:
		Request();
		virtual ~Request();
		Request(const Request &other);
		Request	&operator=(const Request &other);

		//get
		std::string&						get_m_origin();
		std::string&						get_m_body();
		std::string&						get_m_method();
		std::string&						get_m_reqlocation();
		std::string&						get_m_httpver();
		std::map<std::string, std::string>&	get_m_headersMap();
		e_req_status&						get_m_request_status();
		Client*								get_m_client();
		size_t								get_m_remain_body_value();

		//set
		void	set_m_origin(std::string);
		void	set_m_body(std::string);
		void	set_m_method(std::string);
		void	set_m_reqlocation(std::string);
		void	set_m_httpver(std::string);
		// void setHeadersMap();
		void	set_m_request_status(e_req_status);
		void	set_m_client(Client* client);
		void	set_m_remain_body_value(size_t len);

		bool	makeHeader(void);
		bool	makeBody(void);
		bool	checkValidRequest(std::string fin);
		bool	isValidAuthHeader(Location &loc);
		bool	isValidMethod(Location &loc);
		bool	isValidRequestMaxBodySize(Location &loc);

		void	initRequest();
};

#endif