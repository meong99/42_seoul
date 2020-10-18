#include "libft.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char **asd = ft_split("hellolo", 'l');
	while (asd)
	{
		printf("%s\n", *asd);
		asd++;
	}
}
