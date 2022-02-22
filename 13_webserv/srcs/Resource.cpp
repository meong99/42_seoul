#include "../incs/Resource.hpp"

// Resource::Resource()
// {

// }

Resource::Resource(int fd, std::string& response_message, Client* clnt,		\
				   e_resource_type type, e_nextcall nxt, int err) :			\
				   m_raw_data(response_message),
				   m_client(clnt),
				   m_resource_type(type),
				   m_next(nxt),
				   m_response_error_num(err)
{
	m_fd = fd;
	m_fd_type = FD_RESOURCE;
	m_pid = -1;
	m_is_seeked = false;
	m_write_index = 0;
	m_unlink_path.clear();
	m_next = nxt;
}


Resource::~Resource()
{

}

// 멤버변수 getRawData가 참조라서
Resource::Resource(Resource & rsc) : m_raw_data(rsc.m_raw_data)
{
	*this = rsc;
}

Resource& Resource::operator=(Resource& rsc)
{
	m_fd = rsc.m_fd;
	m_fd_type = rsc.m_fd_type;
	m_pid = rsc.m_pid;
	m_is_seeked = rsc.m_is_seeked;
	m_next = rsc.m_next;
	m_raw_data = rsc.m_raw_data;
	m_response_error_num = rsc.m_response_error_num;
	m_resource_type = rsc.m_resource_type;
	m_unlink_path = rsc.m_unlink_path;
	m_write_index = rsc.m_write_index;
	return *this;
}

std::string& Resource::get_m_raw_data()
{
	return m_raw_data;
}

std::string Resource::get_m_unlink_path()
{
	return m_unlink_path;
}

Client* Resource::get_m_client()
{
	return m_client;
}

e_resource_type Resource::get_m_resource_type()
{
	return m_resource_type;
}

e_nextcall Resource::get_m_next()
{
	return m_next;
}

int Resource::get_m_response_error_num()
{
	return m_response_error_num;
}

size_t Resource::get_m_write_index()
{
	return m_write_index;
}

int Resource::get_m_pid()
{
	return m_pid;
}

bool Resource::get_m_is_seeked()
{
	return m_is_seeked;
}

void Resource::set_m_unlink_path(std::string path)
{
	m_unlink_path = path;
}
void Resource::set_m_client(Client * clnt)
{
	m_client = clnt;
}
void Resource::set_m_resource_type(e_resource_type type)
{
	m_resource_type = type;
}
void Resource::set_m_next(e_nextcall next)
{
	m_next = next;
}
void Resource::set_m_response_error_num(int err_num)
{
	m_response_error_num = err_num;
}

void Resource::set_m_write_index(size_t idx)
{
	m_write_index = idx;
}
void Resource::set_m_pid(int pid)
{
	m_pid = pid;
}

void Resource::set_m_is_seeked(bool seeked)
{
	m_is_seeked = seeked;
}

e_rsc_status Resource::isReady(void)
{
	int status;

	if (m_pid == -1)
		return (READY);
	else 
	{
		if (waitpid(m_pid, &status, WNOHANG) == 0)
		{
			return (NOT_YET);
		}
		else
		{
			if (WIFEXITED(status) == 0)
				return (CGI_CRASH);
			else
			{
				if (m_is_seeked == false)
				{
					lseek(m_fd, 0, SEEK_SET);
					m_is_seeked = true;
				}
				return (READY);
			}
		}
	}
		
}