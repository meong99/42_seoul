#include "../incs/Location.hpp"

Location::Location()
{
	m_max_body_size = INT_MAX;
	m_auto_index = false;
	m_return_num = -1;
}

Location::~Location()
{
}

Location::Location(const Location &src)
{
	*this = src;
}

Location&	Location::operator=(const Location &src)
{
	m_max_body_size = src.m_max_body_size;
	m_return_num = src.m_return_num;
	m_auto_index = src.m_auto_index;
	m_root = src.m_root;
	m_upload_path = src.m_upload_path;
	m_uri = src.m_uri;
	m_auth_key = src.m_auth_key;
	m_return_url = src.m_return_url;
	m_allow_methods = src.m_allow_methods;
	m_error_pages = src.m_error_pages;
	m_cgi = src.m_cgi;
	return *this;
}

int		&Location::get_m_max_body_size()
{
	return m_max_body_size;
}

bool	&Location::get_m_auto_index()
{
	return m_auto_index;
}

std::string		&Location::get_m_upload_path()
{
	return m_upload_path;
}

std::string		&Location::get_m_uri()
{
	return m_uri;
}

std::string		&Location::get_m_auth_key()
{
	return m_auth_key;
}

std::string		&Location::get_m_root()
{
	return m_root;
}

int		&Location::get_m_return_num()
{
	return m_return_num;
}

std::string		&Location::get_m_return_url()
{
	return m_return_url;
}

std::vector<std::string>	&Location::get_m_allow_methods()
{
	return m_allow_methods;
}

std::vector<std::string>	&Location::get_m_indexs()
{
	return m_indexs;
}

std::map<int, std::string>	&Location::get_m_error_pages()
{
	return m_error_pages;
}

std::map<std::string, std::string>	&Location::get_m_cgi()
{
	return m_cgi;
}

void	Location::set_m_max_body_size(int size)
{
	m_max_body_size = size;
}

void	Location::set_m_return_num(int return_num)
{
	m_return_num = return_num;
}

void	Location::set_m_auto_index(bool auto_index)
{
	m_auto_index = auto_index;
}

void	Location::set_m_root(std::string root)
{
	m_root = root;
}

void	Location::set_m_upload_path(std::string path)
{
	m_upload_path = path;
}

void	Location::set_m_uri(std::string uri)
{
	m_uri = uri;
}

void	Location::set_m_auth_key(std::string auth_key)
{
	m_auth_key = auth_key;
}

void	Location::set_m_return_url(std::string return_url)
{
	m_return_url = return_url;
}










