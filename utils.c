/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:28:09 by akheired          #+#    #+#             */
/*   Updated: 2024/04/19 15:26:50 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_strncpy(char *dst, char *src, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		dst[i] = src[i];
	dst[i] = '\0';
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	int		count;
	char	**all;

	i = 0;
	j = 0;
	k = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			count++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	i = 0;
	all = malloc(sizeof(char *) * (count + 1));
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			all[k] = malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(all[k++], &str[j], i - j);
		}
	}
	all[k] = NULL;
	return (all);
}

int	borders_check(char **str)
{
	int	rows;
	int	cols;
	int	col;
	int	i;
	int	j;

	rows = 0;
	cols = 0;
	j = 0;
	j = 0;
	while (str[rows])
	{
		col = 0;
		while (str[rows][col] != '\0')
			col++;
		if (col > cols)
			cols = col;
		rows++;
	}
	while (j < cols)
	{
		if (str[0][j] != '1' || str[rows - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < rows)
	{
		if (str[i][0] != '1' || str[i][cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
