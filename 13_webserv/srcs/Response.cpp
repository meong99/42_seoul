#include "../incs/Client.hpp"
#include "../incs/Response.hpp"

Response::Response()
{
	m_return = false;
	m_disconnect = false;
	m_message.clear();
	m_resource_path.clear();
	m_location = NULL;
	m_cgi_extension.clear();
	m_write_idx = 0;
	m_resourceList.clear();
	m_fd_read = -1;
	m_fd_write = -1;
}

Response::~Response()
{
	if (m_fd_read != -1)
		close(m_fd_read);
	if (m_fd_write != -1)
		close(m_fd_write);
	// for문 필요 
}

Response::Response(const Response &other)
{
	*this = other;
}

Response& Response::operator=(const Response &other)
{
	m_return = other.m_return;
	m_disconnect = other.m_disconnect;
	m_client = other.m_client;
	m_message = other.m_message;
	m_resource_path = other.m_resource_path;
	m_location = other.m_location;

	m_cgi_extension = other.m_cgi_extension;
	m_write_idx = other.m_write_idx;

	m_fd_read = other.m_fd_read;
	m_fd_write = other.m_fd_write;
	return (*this);
}

bool Response::get_m_return()
{
	return m_return;
}

bool Response::get_m_disconnect()
{
	return m_disconnect;
}

Client* Response::get_m_client()
{
	return m_client;
}

std::string& Response::get_m_message()
{
	return m_message;
}

std::string Response::get_m_resource_path()
{
	return m_resource_path;
}

Location* Response::get_m_location()
{
	return m_location;
}

std::string Response::get_m_cgi_extension()
{
	return m_cgi_extension;
}

size_t Response::get_m_write_idx()
{
	return m_write_idx;
}

int Response::get_m_fd_read()
{
	return m_fd_read;
}

int Response::get_m_fd_write()
{
	return m_fd_write;
}

std::list<Resource *>& Response::get_m_resourceList()
{
	return m_resourceList;
}


void Response::set_m_return(bool ret)
{
	m_return = ret;
}

void Response::set_m_disconnect(bool disconnect)
{
	m_disconnect = disconnect;
}

void Response::set_m_client(Client* client)
{
	m_client = client;
}

void Response::set_m_message(std::string message)
{
	m_message = message;
}

void Response::set_m_resource_path(std::string path)
{
	m_resource_path = path;
}

void Response::set_m_location(Location *location)
{
	m_location = location;
}

void Response::set_m_cgi_extension(std::string cgi)
{
	m_cgi_extension = cgi;
}

void Response::set_m_write_idx(size_t idx)
{
	m_write_idx = idx;
}

void Response::set_m_fd_read(int fd)
{
	m_fd_read = fd;
}

void Response::set_m_fd_write(int fd)
{
	m_fd_write = fd;
}

void Response::makeGetResponse()
{
	int fd;
	struct stat sb;
	size_t idx;

	if (isDirectory(m_resource_path))
	{
		if (*(--m_resource_path.end()) != '/')
		{
			m_resource_path += '/';
		}
		bool is_exist = false;
		std::string pathwithfile;
		for (std::vector<std::string>::iterator it = m_location->get_m_indexs().begin();
			 it != m_location->get_m_indexs().end(); it++)
		{
			pathwithfile = m_resource_path + (*it);
			is_exist = isExist(pathwithfile);
			if (is_exist == true)
				break;
		}
		if (is_exist == false && m_location->get_m_auto_index() == true)
			return (makeAutoIndexPage());
		m_resource_path = pathwithfile;
	}
	if (!isExist(m_resource_path)) // not found
		return (makeErrorResponse(404));
	if ((fd = open(m_resource_path.c_str(), O_RDONLY)) < 0)
		return (makeErrorResponse(403));
	if (fstat(fd, &sb) < 0)
		return (makeErrorResponse(500));

	// 문제가 없을 경우 헤더 만들기 시작
	addStatusLine(200);
	addDate();
	m_message += "Content-Language: ko-kr\r\n";
	m_message += "Connection: Keep-Alive\r\n";
	m_message += "Keep-Alive: timeout=5, max=1000\r\n";

	idx = m_resource_path.find_first_of('/');
	idx = m_resource_path.find_first_of('.', idx);
	if (idx == std::string::npos)
		addContentType(".arc");
	else
		addContentType(m_resource_path.substr(idx));
	m_message += "Content-Length: " + std::to_string((int)sb.st_size) + "\r\n";
	m_message += "\r\n";
	setResource(fd, READ_RESOURCE, MAKING_RESPONSE);
}

void Response::makePostResponse(void)
{
	if (m_client->get_m_request().get_m_body().size() == 0)
		return (makeErrorResponse(411));
	if (isDirectory(m_resource_path))
	{
		makeErrorResponse(400);
		std::cout << "directory error" << std::endl;
		return;
	}

	int fd;
	if (isExist(m_resource_path))
	{
		if ((fd = open(m_resource_path.c_str(), O_WRONLY | O_APPEND, 0777)) < 0)
		{
			makeErrorResponse(403);
			std::cout << "file create error" << std::endl;
			return;
		}
		addStatusLine(204);
	}
	else
	{
		if ((fd = open(m_resource_path.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0777)) < 0)
		{
			makeErrorResponse(500);
			std::cout << "file open error" << std::endl;
			return;
		}
		addStatusLine(201);
	}
	addDate();
	struct stat sb;
	if (fstat(fd, &sb) < 0)
		return (makeErrorResponse(500));
	addContentLength(0);
	addEmptyLine();
	setResource(fd, WRITE_RESOURCE, MAKING_RESPONSE);
	m_client->set_m_c_status(FILE_WRITING);
}

void Response::makeRedirection(void)
{
	m_message.clear();
	addStatusLine(m_location->get_m_return_num());
	addDate();
	addServer();
	addLocation(m_location->get_m_return_url());
	addEmptyLine();
	
	m_client->set_m_c_status(MAKE_RESPONSE_DONE);
	set_m_disconnect(true);
	return ;
}

void Response::makeDeleteResponse(void)
{
	m_message.clear();
	if (!isExist(m_resource_path))
		makeErrorResponse(404);
	else
	{
		if (isDirectory(m_resource_path))
			makeErrorResponse(403);
		else
		{
			// int fd;
			// if ((fd = open(m_resource_path.c_str(), O_RDONLY)) < 0)
			//     return (makeErrorResponse(403));
			// close(fd);
			int del = unlink(m_resource_path.c_str());  // unlink전에 fd close 해야 합니다!
			if (del < 0)
				makeErrorResponse(403);
			else
			{
				addStatusLine(204);
				addDate();
				addServer();
				addContentLength(0);
				addEmptyLine();
				m_client->set_m_c_status(MAKE_RESPONSE_DONE);
			}
		}
	}
}

void Response::makeErrorResponse(int errorcode)
{
	m_message.clear();
	addStatusLine(errorcode);
	addDate();
	addContentLanguage();
	addServer();
	addContentType(".html");
	if (errorcode == 401)
		addWWWAuthenticate();
	if (errorcode == 405)
		addAllowMethod();
	if (errorcode == 408)
		m_message += "Connection: close\r\n";
	if (m_location->get_m_error_pages().count(errorcode) == 0)  // default 에러 페이지 없으면
		return(addErrorBody(errorcode));

	std::string resource_path = get_m_location()->get_m_error_pages()[errorcode];
	struct stat sb;
	int fd;
	if ((fd = open(resource_path.c_str(), O_RDONLY)) < 0)
		return (addErrorBody(errorcode));
	else
	{
		if (fstat(fd, &sb) < 0)
			return (addErrorBody(errorcode));
		else
		{
			addContentLength(int(sb.st_size));
			addEmptyLine();
			setResource(fd, READ_RESOURCE, MAKING_RESPONSE);
		}
	}
}

void Response::makeAutoIndexPage(void)
{
	m_message.clear();

	addStatusLine(200);
	addContentLanguage();
	addContentType(".html");
	addDate();

	std::string body = "";
	body += "<!DOCTYPE html>\n";
	body += "<html>\n";
	body += "<head>\n";
	body += "</head>\n";
	body += "<body>";
	body += "autoindex page\n\n";
	body += "<br><br>";
	makeFileList(body);
	body += "</body>\n";
	body += "</html>\n";
	addContentLength(body.size());
	addEmptyLine();
	m_message += body;
	m_client->set_m_c_status(MAKE_RESPONSE_DONE);

}

void Response::makeFileList(std::string &body)
{
	std::string http_host_port = "http://" + m_client->get_m_request().get_m_headersMap()["Host"] + m_client->get_m_request().get_m_reqlocation() ;  // <host>:<port>
    if (http_host_port[http_host_port.length()-1] != '/')
        http_host_port += "/";
    DIR *dir = NULL;
	struct dirent *directory = NULL;

	if ((dir = opendir(m_resource_path.c_str())) == NULL)
		return (makeErrorResponse(500));
	while ((directory = readdir(dir)))
	{
		std::string file_name(directory->d_name);
		if (file_name != "." && file_name != "..")
		{
			body += "<a href=" + http_host_port + file_name + " >" + file_name + "</a><br>";
			// std::cout << "<a href=" + http_host_port + file_name + " >" + file_name + "</a><br>" << std::endl;
		}
	}
	closedir(dir);
}

void Response::setResource(int res_fd, e_resource_type type, e_nextcall ctype, int errornum)
{
	Resource* res;
	
	Webserv* webserv = Config::get_m_config()->get_m_webserv();

	if (type == WRITE_RESOURCE)
	{
		 res = new Resource(res_fd, m_client->get_m_request().get_m_body(), m_client, WRITE_RESOURCE, ctype, errornum);
		 m_resourceList.push_back(res);
		 webserv->addFdPool(dynamic_cast<FdBase*>(res));
		 webserv->change_events(webserv->get_m_change_list(), res_fd, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
	}
	else if (type == READ_RESOURCE)
	{
		res = new Resource(res_fd, m_message, m_client, READ_RESOURCE, ctype, errornum);
		m_resourceList.push_back(res);
		webserv->addFdPool(dynamic_cast<FdBase *>(res));
		webserv->change_events(webserv->get_m_change_list(), res_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);  
	}
}

void Response::initResponse()
{
	m_return = false;
	m_disconnect = false;
	m_message.clear();
	m_resource_path.clear();
	m_location = NULL;
	m_cgi_extension.clear();
	m_write_idx = 0;
	m_resourceList.clear();
	m_fd_read = -1;
	m_fd_write = -1;
}

