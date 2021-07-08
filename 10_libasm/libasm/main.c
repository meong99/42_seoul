/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohelee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:09:57 by sohelee           #+#    #+#             */
/*   Updated: 2021/05/11 19:04:15 by sohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	write_test(void)
{
	printf("[unistd] write = %zd\n", write(1, "sohelee!", 9));
	printf("[libasm] ft_write = %zd\n", ft_write(1, "sohelee!", 9));
	printf("\n");
}

void	read_test(void)
{
	int		fd;
	char	unistdbuf[50];
	char	libasmbuf[50];
	ssize_t	ret;

	fd = open("Makefile", O_RDONLY);
	ret = read(fd, unistdbuf, 5);
	close(fd);
	printf("1) [unistd] : %zd\n", ret);
	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, libasmbuf, 5);
	printf("1) [libasm] : %zd\n", ret);
	close(fd);
	fd = open("I don't exist", O_RDONLY);
	ret = read(fd, unistdbuf, 5);
	close(fd);
	printf("2) [unistd] : %zd\n", ret);
	fd = open("I don't exist", O_RDONLY);
	ret = ft_read(fd, libasmbuf, 5);
	printf("2) [libasm] : %zd\n", ret);
	close(fd);
	printf("\n");
}

int		main(void)
{
	char s[50];

	printf("______TESTING <ft_strlen>______\n");
	printf("[string] strlen = %zu\n", strlen("sohelee!"));
	printf("[libasm] ft_strlen = %zu\n\n", ft_strlen("sohelee!"));
	printf("______TESTING <ft_strcpy>______\n");
	printf("[string] strcpy = %s\n", strcpy(s, "sohelee!"));
	printf("[libasm] ft_strcpy = %s\n\n", ft_strcpy(s, "sohelee!"));
	printf("______TESTING <ft_strcmp>______\n");
	printf("[string] strcmp = %d\n", strcmp("a", "b"));
	printf("[libasm] ft_strcmp = %d\n\n", ft_strcmp("a", "b"));
	printf("______TESTING <ft_write>______\n");
	write_test();
	printf("______TESTING <ft_read>______\n");
	read_test();
	printf("______TESTING <ft_strdup>______\n");
	printf("[string] strdup = %s\n", strdup("HelloWorld!"));
	printf("[libasm] ft_strdup = %s\n\n", ft_strdup("HelloWorld!"));
	return (1);
}
