#ifndef LOCATION_HPP
# define LOCATION_HPP

#include <string>
#include <map>
#include <vector>
#include <limits>

class Location {
	private:
		int									m_max_body_size;
		int									m_return_num;
		bool								m_auto_index;
		std::string							m_root;
		std::string							m_upload_path; // where are you from 
		std::string							m_uri;
		std::string							m_auth_key;
		std::string							m_return_url;
		std::vector<std::string>			m_allow_methods;
		std::vector<std::string>			m_indexs;
		std::map<int, std::string>			m_error_pages;
		std::map<std::string, std::string>	m_cgi;
	
	public:
		Location();
		virtual ~Location();
		Location(const Location &src);
		Location&	operator=(const Location &src);

		//get
		int&								get_m_max_body_size();
		bool&								get_m_auto_index();
		std::string&						get_m_upload_path();
		std::string&						get_m_uri();
		std::string&						get_m_auth_key();
		std::string&						get_m_root();
		int&								get_m_return_num();
		std::string&						get_m_return_url();
		std::vector<std::string>&			get_m_allow_methods();
		std::vector<std::string>&			get_m_indexs();
		std::map<int, std::string>&			get_m_error_pages();
		std::map<std::string, std::string>&	get_m_cgi();

		//set
		void	set_m_max_body_size(int size);
		void	set_m_return_num(int return_num);
		void	set_m_auto_index(bool auto_index);
		void	set_m_root(std::string root);
		void	set_m_upload_path(std::string path);
		void	set_m_uri(std::string uri);
		void	set_m_auth_key(std::string auth_key);
		void	set_m_return_url(std::string return_url);
};

#endif