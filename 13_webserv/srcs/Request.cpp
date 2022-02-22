#include "../incs/Request.hpp"
#include "../incs/Config.hpp"

Request::Request()
{
	m_request_status = HEADER_PARSING;
}

Request::~Request()
{

}

Request::Request(const Request& other)
{
	*this = other;
}

Request& Request::operator=(const Request& other)
{
	m_origin = other.m_origin;
	m_body = other.m_body;
	m_method = other.m_method;
	m_reqlocation = other.m_reqlocation;
	m_httpver = other.m_httpver;
	for (std::map<std::string, std::string>::const_iterator					\
			it = other.m_headersMap.begin();								\
			it != other.m_headersMap.end(); it++)
	{
		m_headersMap[it->first] = it->second;
	}
	return *this;
}

std::string& Request::get_m_origin()
{
	return m_origin;
}

std::string& Request::get_m_body()
{
	return m_body;
}

std::string& Request::get_m_method()
{
	return m_method;
}

std::string& Request::get_m_reqlocation()
{
	return m_reqlocation;
}

std::string& Request::get_m_httpver()
{
	return m_httpver;
}

std::map<std::string, std::string>& Request::get_m_headersMap()
{
	return m_headersMap;
}

e_req_status& Request::get_m_request_status()
{
	return m_request_status;
}

Client* Request::get_m_client()
{
	return m_client;
}

size_t Request::get_m_remain_body_value()
{
	return m_remain_body_value;
}


void Request::set_m_origin(std::string origin)
{
	m_origin = origin;
}

void Request::set_m_body(std::string body)
{
	m_body = body;
}

void Request::set_m_method(std::string method)
{
	m_method = method;
}

void Request::set_m_reqlocation(std::string location)
{
	m_reqlocation = location;
}

void Request::set_m_httpver(std::string httpver)
{
	m_httpver = httpver;
}

void Request::set_m_request_status(e_req_status status)
{
	m_request_status = status;
}

void Request::set_m_client(Client* client)
{
	m_client = client;
}

void Request::set_m_remain_body_value(size_t len)
{
	m_remain_body_value = len;
}

std::string trim(std::string& str)
{
	std::size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first)
	{
		return str;
	}
	std::size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

int		 	Request::base64_decode(const char * text, char * dst, int numBytes)
{
	const char* cp;
	int space_idx = 0, phase;
	int d, prev_d = 0;
	char c;
	space_idx = 0;
	phase = 0;
	for (cp = text; *cp != '\0'; ++cp) {
		d = Config::decodeMimeBase64[(int)*cp];
		if (d != -1) {
			switch (phase) {
			case 0:
				++phase;
				break;
			case 1:
				c = ((prev_d << 2) | ((d & 0x30) >> 4));
				if (space_idx < numBytes)
					dst[space_idx++] = c;
				++phase;
				break;
			case 2:
				c = (((prev_d & 0xf) << 4) | ((d & 0x3c) >> 2));
				if (space_idx < numBytes)
					dst[space_idx++] = c;
				++phase;
				break;
			case 3:
				c = (((prev_d & 0x03) << 6) | d);
				if (space_idx < numBytes)
					dst[space_idx++] = c;
				phase = 0;
				break;
			}
			prev_d = d;
		}
	}
	return space_idx;
}

bool Request::makeHeader(void)
{
	std::size_t found = m_origin.find("\r\n");
	std::vector<std::string> vFirsts;
	std::string firstline = m_origin.substr(0, found);
	ft_split(firstline, " ", vFirsts);
	set_m_method(vFirsts[0]);
	set_m_reqlocation(vFirsts[1]);
	set_m_httpver(vFirsts[2]);
	if (m_origin.length() >= found+2)
		set_m_origin(m_origin.substr(found+2));
	else
		set_m_origin("");

	found = m_origin.find("\r\n\r\n");
	std::string tempheader = m_origin.substr(0, found);
	std::vector<std::string> tempVHeaders;
	ft_split(tempheader, "\r\n", tempVHeaders);
	for (std::vector<std::string>::iterator it = tempVHeaders.begin();		\
											it != tempVHeaders.end(); it++)
	{
		std::string line = *it;
		std::size_t idx = line.find(':');
		std::string key = line.substr(0, idx);
		std::string value = "";
		if (line.length() != (found+1))
			value = line.substr(idx+1);
		m_headersMap[trim(key)] = trim(value);
	}
	if (m_origin.length() >= found+4)
		set_m_origin(m_origin.substr(found+4));
	else
		set_m_origin("");
	return true;
}
bool Request::makeBody(void)
{
	if (m_request_status == CONTENT_BODY)
	{
		if (m_remain_body_value <= m_origin.length())
		{
			m_body.append(m_origin.substr(0, m_remain_body_value));
			m_origin.erase(0, m_remain_body_value);
			m_remain_body_value = 0;
			return (checkValidRequest("FINISHED"));
		}
		return (false);
	}
	else if (m_request_status == CHUNKED)
	{
		size_t tmp;
		std::stringstream ss;
		std::size_t found = m_origin.find("\r\n");
		if (found == std::string::npos)
			return false;
		else
		{
			ss << std::hex << m_origin.substr(0, found);
			ss >> tmp;
			m_remain_body_value = tmp + 2;
			m_origin = m_origin.substr(found+2);
			m_request_status = CHUNKED_BODY;
			return (makeBody());
		}
	}
	else if (CHUNKED_BODY)
	{
		if (m_remain_body_value <= m_origin.size())
		{
			size_t oldbodysize = m_body.size();
			m_body.append(m_origin.substr(0, m_remain_body_value -2));
			m_origin.erase(0, m_remain_body_value);

			m_remain_body_value = 0;
			if (m_body.size() == oldbodysize)
			{
				return (checkValidRequest("FINISHED"));
			}
			m_request_status = CHUNKED;
			return (makeBody());
		}
	}
	return (checkValidRequest("FINISHED"));
}

bool Request::checkValidRequest(std::string fin)
{
	if (fin != "FINISHED")
	{
		std::cout << "checkValidRequest return false" << std::endl;
		return false;
	}
	// 파싱이 끝났으면 올바른지 확인하는 코드가 밑에 있다 
	Location &loc = m_client->get_m_server()->getPerfectLocation(m_reqlocation);
	m_client->get_m_response().set_m_location(&loc);

	if (isValidAuthHeader(loc) == false)
	{
		m_client->set_m_c_status(MAKE_RESPONSE);
		m_client->get_m_response().makeErrorResponse(401);
		return (false);
	}
	if (isValidMethod(loc) == false)
	{
		m_client->set_m_c_status(MAKE_RESPONSE);
		m_client->get_m_response().makeErrorResponse(405);
		return (false);
	}
	if (isValidRequestMaxBodySize(loc) == false)
	{
		m_client->set_m_c_status(MAKE_RESPONSE);
		m_client->get_m_response().makeErrorResponse(413);
		return (false);
	}

	//GET /index.html http1.1
	std::string resource_path = loc.get_m_root() + m_reqlocation.substr(loc.get_m_uri().size());
	m_client->get_m_response().set_m_resource_path(resource_path);

	for (std::map<std::string, std::string>::iterator iter = loc.get_m_cgi().begin(); iter != loc.get_m_cgi().end(); iter++)
	{
		if (resource_path.find(iter->first) != std::string::npos) // cgi_extention 표현을 찾았다면
		{
			m_client->get_m_response().set_m_cgi_extension(iter->first);
			break;
		}
	}
	if (loc.get_m_return_num() != -1)
		m_client->get_m_response().set_m_return(true);

	set_m_request_status(HEADER_PARSING);
	return true;
}

bool	Request::isValidAuthHeader(Location &loc)
{
	if (loc.get_m_auth_key() != "")
	{
		char result[200];
		memset(result, 0, 200);

		if (m_headersMap.find("Authorization") == m_headersMap.end())  // auth key 헤더가 아예 안들어왔다.
		{
			return (false);
		}
		else
		{
			size_t idx = m_headersMap["Authorization"].find_first_of(' ');
			std::string secret = m_headersMap["Authorization"].substr(idx + 1);
			base64_decode(secret.c_str(), result, secret.size());
			if (std::string(result) != loc.get_m_auth_key()) // 키가 맞지 않는다.
				return (false);
		}
	}
	return (true);
}

bool	Request::isValidMethod(Location &loc)
{
	bool isAllowCheckOkay = false;
	for (std::vector<std::string>::iterator iter = loc.get_m_allow_methods().begin(); iter != loc.get_m_allow_methods().end(); iter++)
	{
		if (m_method == *iter)
		{
			isAllowCheckOkay = true;
			break ;
		}
	}
	if (isAllowCheckOkay != true) // allow method check 가 안되었다. -> 405
		return (false);
	return (true);
}

bool	Request::isValidRequestMaxBodySize(Location &loc)
{
	if (m_body.size() > (size_t)(loc.get_m_max_body_size()))
		return (false);
	return (true);
}

void Request::initRequest()
{
	m_origin.clear();
	m_body.clear();
	m_method.clear();
	m_reqlocation.clear();
	m_httpver.clear();
	m_headersMap.clear();
	m_request_status = HEADER_PARSING;
	m_remain_body_value = 0;
}