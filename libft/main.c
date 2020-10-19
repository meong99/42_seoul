#include "libft.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char **asd = ft_split("lllllhlhllasdlllasd", 'l');
	while (*asd)
	{
		printf("%s\n", *asd);
		asd++;
	}
}
