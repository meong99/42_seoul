#include "../incs/Config.hpp"
#include <signal.h>

void signalhandler(int sigint)
{
	if (sigint == 2)
	{
		std::cout << "signal 보내 signal  보내!!" << std::endl;
		Config::get_m_config()->get_m_webserv()->signalExit();
	}
	exit(1);  // 숫자 뭐해야함?
}

int main(int argc, char **argv)
{
	Config *config;

	config = Config::get_m_config();
	try 
	{
		if (argc < 2)
			config->parsingConfig(std::string("./configs/default.config"));
		if (argc >= 2)
			config->parsingConfig(std::string(argv[1]));

	}	
	catch(const char* e)
	{
		std::cerr << e << '\n';
		exit(1);
	}
	Webserv webserv;

	signal(SIGINT, signalhandler);
	config->set_m_webserv(&webserv);
	config->get_m_webserv()->startServer();
	
}