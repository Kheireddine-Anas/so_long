/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:28:09 by akheired          #+#    #+#             */
/*   Updated: 2024/04/23 18:54:35 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				printf("GOLK");
			j++;
		}
		i++;
	}
}

void	errors_msg(int msg_num)
{
	if (msg_num == 2)
		write(1, "Error\nCheck Map Elements\n", 26);
	if (msg_num == 3)
		write(1, "Error\nCheck The Map\n", 21);
	if (msg_num == 4)
		write(1, "Error\nCheck The Map Path\n", 26);
	if (msg_num == 5)
		write(1, "Error\nCheck The Map File", 7);
	exit(1);
}

void	finish_game(void)
{
	write(1, "GAME OVER!", 11);
	exit(0);
}

int	map_left(t_game *map)
{
	if (map->gui_map[map->px][map->py - 1] != 'E' &&
			map->gui_map[map->px][map->py - 1] != '1')
	{
		if (map->gui_map[map->px][map->py - 1] == 'C')
			map->gui_coins--;
		map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px][map->py - 1] = 'P';
		map->py--;
		mlx_clear_window(map->mlx, map->mlx_win);
		show_game(map);
		return (1);
	}
	if ((map->gui_coins == 0) && (map->gui_map[map->px][map->py - 1] == 'E'))
		finish_game();
	return (0);
}

int	map_right(t_game *map)
{
	if (map->gui_map[map->px][map->py + 1] != 'E' &&
			map->gui_map[map->px][map->py + 1] != '1')
	{
		if (map->gui_map[map->px][map->py + 1] == 'C')
			map->gui_coins--;
		map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px][map->py + 1] = 'P';
		map->py++;
		mlx_clear_window(map->mlx, map->mlx_win);
		show_game(map);
		return (1);
	}
	if ((map->gui_coins == 0) && (map->gui_map[map->px][map->py + 1] == 'E'))
		finish_game();
	return (0);
}

int	map_down(t_game *map)
{
	if (map->gui_map[map->px + 1][map->py] != 'E' &&
			map->gui_map[map->px + 1][map->py] != '1')
	{
		if (map->gui_map[map->px + 1][map->py] == 'C')
			map->gui_coins--;
		map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px + 1][map->py] = 'P';
		map->px++;
		mlx_clear_window(map->mlx, map->mlx_win);
		show_game(map);
		return (1);
	}
	if ((map->gui_coins == 0) && (map->gui_map[map->px + 1][map->py] == 'E'))
		finish_game();
	return (0);
}

int	map_up(t_game *map)
{
	if (map->gui_map[map->px - 1][map->py] != 'E' &&
			map->gui_map[map->px - 1][map->py] != '1')
	{
		if (map->gui_map[map->px - 1][map->py] == 'C')
			map->gui_coins--;
		map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px - 1][map->py] = 'P';
		map->px--;
		mlx_clear_window(map->mlx, map->mlx_win);
		show_game(map);
		return (1);
	}
	if ((map->gui_coins == 0) && (map->gui_map[map->px - 1][map->py] == 'E'))
		finish_game();
	return (0);
}
