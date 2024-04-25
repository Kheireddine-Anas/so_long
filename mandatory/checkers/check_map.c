/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:09:17 by akheired          #+#    #+#             */
/*   Updated: 2024/04/25 12:56:32 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	borders_check(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->cp_map[i])
	{
		j = 0;
		while (map->cp_map[i][j] && map->cp_map[i][j] != '\n')
		{
			if (map->cp_map[0][j] != '1' || map->cp_map[i][0] != '1' ||
			map->cp_map[map->line - 1][j] != '1' ||
			map->cp_map[i][map->length - 1] != '1')
				errors_msg(7);
			j++;
		}
		i++;
	}
}

void	elements_check(t_game *map, int i, int j)
{
	while (map->cp_map[i])
	{
		j = 0;
		while (map->cp_map[i][j])
		{
			if (map->cp_map[i][j] == '\n')
				j++;
			if (map->cp_map[i][j] == 'P')
			{
				map->px = i;
				map->py = j;
				map->player++;
			}
			else if (map->cp_map[i][j] == 'C')
				map->coins++;
			else if (map->cp_map[i][j] == 'E')
				map->exit++;
			else if (map->cp_map[i][j] != '0' && map->cp_map[i][j] != 'C' &&
				map->cp_map[i][j] != 'E' && map->cp_map[i][j] != '1' &&
				map->cp_map[i][j] != 'P')
				errors_msg(2);
			j++;
		}
		i++;
	}
}

void	elements_check_num(t_game *map)
{
	if (map->coins < 1 || map->player != 1 || map->exit != 1)
		errors_msg(2);
}

void	path_check_recursive(t_game *map, int x, int y)
{
	path_check(map, x, y + 1);
	path_check(map, x, y - 1);
	path_check(map, x + 1, y);
	path_check(map, x - 1, y);
}

int	path_check(t_game *map, int x, int y)
{
	if (map->cp_map[x][y] == 'P')
	{
		map->cp_map[x][y] = '1';
		path_check_recursive(map, x, y);
	}
	else if (map->cp_map[x][y] == 'E')
	{
		map->exit--;
		map->cp_map[x][y] = '1';
		path_check_recursive(map, x, y);
	}
	else if (map->cp_map[x][y] == 'C')
	{
		map->coins--;
		map->cp_map[x][y] = '1';
		path_check_recursive(map, x, y);
	}
	else if (map->cp_map[x][y] == '0')
	{
		map->cp_map[x][y] = '1';
		path_check_recursive(map, x, y);
	}
	if (map->coins == 0 && map->exit == 0)
		return (0);
	return (1);
}
