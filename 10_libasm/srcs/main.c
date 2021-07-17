/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:41:05 by mchae             #+#    #+#             */
/*   Updated: 2021/07/17 17:41:06 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	write_test(void)
{
	printf("[unistd] write = %zd\n", write(1, "mchae!", 9));
	printf("[libasm] ft_write = %zd\n", ft_write(1, "mchae!", 9));
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
	printf("[string] strlen = %zu\n", strlen("mchae!"));
	printf("[libasm] ft_strlen = %zu\n\n", ft_strlen("mchae!"));
	printf("______TESTING <ft_strcpy>______\n");
	printf("[string] strcpy = %s\n", strcpy(s, "mchae!"));
	printf("[libasm] ft_strcpy = %s\n\n", ft_strcpy(s, "mchae!"));
	printf("______TESTING <ft_strcmp>______\n");
	printf("[string] strcmp = %d\n", strcmp("abcde", "abcd"));
	printf("[libasm] ft_strcmp = %d\n\n", ft_strcmp("abcde", "abcd"));
	printf("______TESTING <ft_write>______\n");
	write_test();
	printf("______TESTING <ft_read>______\n");
	read_test();
	printf("______TESTING <ft_strdup>______\n");
	printf("[string] strdup = %s\n", strdup("HelloWorld!"));
	printf("[libasm] ft_strdup = %s\n\n", ft_strdup("HelloWorld!"));
	return (0);
}
