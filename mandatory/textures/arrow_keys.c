/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:25:42 by akheired          #+#    #+#             */
/*   Updated: 2024/04/25 12:58:09 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	finish_game(void)
{
	write(1, "GAME OVER!\n", 12);
	exit(0);
}

int	map_left(t_game *map)
{
	pleft(map);
	if (map->gui_map[map->px][map->py - 1] != 'E' &&
			map->gui_map[map->px][map->py - 1] != '1')
	{
		if (map->gui_map[map->px][map->py - 1] == 'C')
			map->gui_coins--;
		if (map->gui_map[map->px][map->py] == 'X')
			map->gui_map[map->px][map->py] = 'E';
		else
			map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px][map->py - 1] = 'P';
		map->py--;
		show_game(map, 0, 0);
		return (1);
	}
	else if (map->gui_map[map->px][map->py - 1] == 'E')
	{
		eleft(map);
		show_game(map, 0, 0);
		return (1);
	}
	return (0);
}

int	map_right(t_game *map)
{
	pright(map);
	if (map->gui_map[map->px][map->py + 1] != 'E' &&
			map->gui_map[map->px][map->py + 1] != '1')
	{
		if (map->gui_map[map->px][map->py + 1] == 'C')
			map->gui_coins--;
		if (map->gui_map[map->px][map->py] == 'X')
			map->gui_map[map->px][map->py] = 'E';
		else
			map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px][map->py + 1] = 'P';
		map->py++;
		show_game(map, 0, 0);
		return (1);
	}
	else if (map->gui_map[map->px][map->py + 1] == 'E')
	{
		eright(map);
		show_game(map, 0, 0);
		return (1);
	}
	return (0);
}

int	map_down(t_game *map)
{
	if (map->gui_map[map->px + 1][map->py] != 'E' &&
			map->gui_map[map->px + 1][map->py] != '1')
	{
		if (map->gui_map[map->px + 1][map->py] == 'C')
			map->gui_coins--;
		if (map->gui_map[map->px][map->py] == 'X')
			map->gui_map[map->px][map->py] = 'E';
		else
			map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px + 1][map->py] = 'P';
		map->px++;
		show_game(map, 0, 0);
		return (1);
	}
	else if (map->gui_map[map->px + 1][map->py] == 'E')
	{
		if (map->gui_coins == 0)
			finish_game();
		map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px + 1][map->py] = 'X';
		map->px++;
		show_game(map, 0, 0);
		return (1);
	}
	return (0);
}

int	map_up(t_game *map)
{
	if (map->gui_map[map->px - 1][map->py] != 'E' &&
			map->gui_map[map->px - 1][map->py] != '1')
	{
		if (map->gui_map[map->px - 1][map->py] == 'C')
			map->gui_coins--;
		if (map->gui_map[map->px][map->py] == 'X')
			map->gui_map[map->px][map->py] = 'E';
		else
			map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px - 1][map->py] = 'P';
		map->px--;
		show_game(map, 0, 0);
		return (1);
	}
	else if (map->gui_map[map->px - 1][map->py] == 'E')
	{
		if (map->gui_coins == 0)
			finish_game();
		map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px - 1][map->py] = 'X';
		map->px--;
		show_game(map, 0, 0);
		return (1);
	}
	return (0);
}
