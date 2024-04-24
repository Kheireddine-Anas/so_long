/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:28:09 by akheired          #+#    #+#             */
/*   Updated: 2024/04/24 02:54:29 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*hld;
	size_t	i;

	i = -1;
	hld = malloc(count * size);
	if (!hld)
		return (NULL);
	while (++i < size)
		hld[i] = 0;
	return (hld);
}

char	*line_con(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1)+ ft_strlen(s2)) + 1);
	if (!str)
		return (0);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	return (str);
}

void	args_exe(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 7);
		exit(1);
	}
	while (argv[1][i])
		i++;
	if (!(argv[1][i - 5]) || argv[1][i - 4] != '.' || argv[1][i - 3] != 'b'
		|| argv[1][i - 2] != 'e' || argv[1][i - 1] != 'r')
	{
		write(1, "Error\n", 7);
		write(1, "Map Extention .ber\n", 20);
		exit(1);
	}
}

void	errors_msg(int msg_num)
{
	if (msg_num == 2)
		write(1, "Error\nCheck Map Elements\n", 26);
	else if (msg_num == 3)
		write(1, "Error\nCheck The Map\n", 21);
	else if (msg_num == 4)
		write(1, "Error\nCheck The Map Path\n", 26);
	else if (msg_num == 5)
		write(1, "Error\nCheck The Map File", 7);
	else if (msg_num == 6)
		write(1, "Error\nCheck The Images", 23);
	else if (msg_num == 7)
		write(1, "Error\nYou Lose!", 16);
	exit(1);
}
