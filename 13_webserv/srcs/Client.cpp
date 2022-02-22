#include "../incs/Client.hpp"

Client::Client()
{
	m_server = 0;
	m_c_status = REQUEST_RECEIVING;
	m_fd_type = FD_CLIENT;
	m_fd = -1;
	m_request.set_m_client(this);
	m_response.set_m_client(this);
	struct timeval tv;
	gettimeofday(&tv, NULL);
	m_last_time =  (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

Client::Client(Server *server, int c_fd)
{
	m_server = server;
	m_c_status = REQUEST_RECEIVING;
	m_fd_type = FD_CLIENT;
	m_fd = c_fd;
	m_request.set_m_client(this);
	m_response.set_m_client(this);
	struct timeval tv;
	gettimeofday(&tv, NULL);
	m_last_time =  (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
Client::~Client()
{

}

Client::Client(const Client &other)
{
	*this = other;
}

Client &Client::operator=(const Client &other)
{
	m_server = other.m_server;
	m_c_status = other.m_c_status;
	m_fd_type = other.m_fd_type;
	m_fd = other.m_fd;
	return (*this);
}

Request &Client::get_m_request(void)
{
	return (m_request);
}

Response &Client::get_m_response(void)
{
	return (m_response);
}

e_c_status &Client::get_m_c_status(void)
{
	return (m_c_status);
}

unsigned long &Client::get_m_last_time(void)
{
	return (m_last_time);
}

Server* Client::get_m_server(void)
{
	return (m_server);
}

void Client::set_m_last_time(unsigned long last_time)
{
	m_last_time = last_time;
}

void Client::set_m_c_status(e_c_status c_status)
{
	m_c_status = c_status;
}

void Client::appendOrigin(std::string newstr)
{
	get_m_request().get_m_origin() += newstr;
}

bool Client::parseRequest()
{
	// m_request.setClient(this);  //
	if (m_request.get_m_request_status() == HEADER_PARSING)
	{
		std::size_t idx = m_request.get_m_origin().find("\r\n\r\n");
		if (idx == std::string::npos)
			return false;
		// m_request.makeStartLine();
		m_request.makeHeader(); // startline, header
		m_request.set_m_request_status(BODY_PARSING);
	}
	if (m_request.get_m_request_status() == BODY_PARSING)
	{
		if ((m_request.get_m_headersMap().count("Transfer-Encoding") == 1) && \
		(m_request.get_m_headersMap()["Transfer-Encoding"] == "chunked"))
		{
			m_request.set_m_request_status(CHUNKED);
			return (m_request.makeBody());
		}
		else if (m_request.get_m_headersMap().count("Content-Length"))
		{
			m_request.set_m_remain_body_value(atoi(m_request.get_m_headersMap()["Content-Length"].c_str()));
			if (m_request.get_m_remain_body_value() == 0)
			{
				return (m_request.checkValidRequest("FINISHED"));
			}
			m_request.set_m_request_status(CONTENT_BODY);
			return (m_request.makeBody());
		}
		else
			return (m_request.checkValidRequest("FINISHED"));
	}
	
	return (m_request.makeBody());
}

void Client::makeResponse()
{
    if(m_response.get_m_cgi_extension() != "")
        return (m_response.makeCgiResponse());
    if (m_response.get_m_return()) 
        return (m_response.makeRedirection());
    
    if(m_request.get_m_method() == "GET")
    {
		if (get_m_c_status() == MAKE_RESPONSE)
			m_response.makeGetResponse();
		else if (get_m_c_status() == FILE_READ_DONE)
			set_m_c_status(MAKE_RESPONSE_DONE);
		return ;
	}
	if (m_request.get_m_method() == "POST")
	{
		if (get_m_c_status() == MAKE_RESPONSE)
			m_response.makePostResponse();
		else if (get_m_c_status() == FILE_WRITE_DONE)
			set_m_c_status(MAKE_RESPONSE_DONE);
	}
	if(m_request.get_m_method() == "DELETE")
	{
		if (get_m_c_status() == MAKE_RESPONSE)
			m_response.makeDeleteResponse();
		else if (get_m_c_status() == FILE_READ_DONE)
			set_m_c_status(MAKE_RESPONSE_DONE);
		return ;
	}
	
}

void Client::initRequestandResponse()
{
	m_request.initRequest();
	m_response.initResponse();
}