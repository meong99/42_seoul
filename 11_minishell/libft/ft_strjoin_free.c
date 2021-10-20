#include "libft.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*new_str;
	size_t	join_str_len;

	if (!s2)
		return (s1);
	join_str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(join_str_len);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, join_str_len);
	ft_strlcat(new_str, s2, join_str_len);
	free((char *)s1);
	return (new_str);
}
