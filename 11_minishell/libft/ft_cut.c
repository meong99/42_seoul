#include "libft.h"

char	*ft_cut(char *str, char *start, char *end)
{
	int		len;
	char	*result;
	int		i;

	if (!str | !start | !end)
		return (NULL);
	if (start < str || end > str + ft_strlen(str))
		return (NULL);
	if (end < start || *end == '\0')
		return (NULL);
	len = start - str;
	len += ft_strlen(end + 1);
	result = malloc(len + 1);
	i = 0;
	while (*str)
	{
		if (!(str >= start && str <= end))
			result[i++] = *str;
		str++;
	}
	result[i] = 0;
	return (result);
}
