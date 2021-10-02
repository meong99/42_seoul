#include "minishell.h"

void	arg(void *str)
{
	if (str == NULL)
		return ;
	printf("arg=%s ", (char *)str);
}

void	re(void *str)
{
	if (str == NULL)
		return ;
	printf("re=%s ", (char *)str);
}

void	file(void *str)
{
	if (str == NULL)
		return ;
	printf("file=%s ", (char *)str);
}

void	del(void *str)
{
	if (str == NULL)
		return ;
	printf("del=%s ", (char *)str);
}

void	delete(void *str)
{
	free(str);
}
