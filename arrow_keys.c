/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:25:42 by akheired          #+#    #+#             */
/*   Updated: 2024/04/23 22:51:24 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish_game(void)
{
	write(1, "GAME OVER!\n", 12);
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
		show_game(map, 0, 0);
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
		show_game(map, 0, 0);
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
		show_game(map, 0, 0);
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
		show_game(map, 0, 0);
		return (1);
	}
	if ((map->gui_coins == 0) && (map->gui_map[map->px - 1][map->py] == 'E'))
		finish_game();
	return (0);
}
