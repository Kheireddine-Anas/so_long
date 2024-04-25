/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:25:42 by akheired          #+#    #+#             */
/*   Updated: 2024/04/24 00:00:57 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish_game(void)
{
	write(1, "GAME OVER!\n", 12);
	exit(0);
}

void	pleft(t_game *map)
{
	map->img_player = mlx_xpm_file_to_image(map->mlx, "src/ply_left.xpm",
			&map->img_width, &map->img_height);
	map->img_epl = mlx_xpm_file_to_image(map->mlx, "src/epl.xpm",
			&map->img_width, &map->img_height);
}
int	map_left(t_game *map)
{
	pleft(map);
	if (map->gui_map[map->px][map->py - 1] != 'E' &&
			map->gui_map[map->px][map->py - 1] != '1')
	{
		if (map->gui_map[map->px][map->py - 1] == 'C')
			map->gui_coins--;
		else if (map->gui_map[map->px][map->py - 1] == 'A')
			errors_msg(7);
		if ((map->gui_map[map->px][map->py] == 'X'))
			map->gui_map[map->px][map->py] = 'E';
		else
			map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px][map->py - 1] = 'P';
		map->py--;
	}
	else if (map->gui_map[map->px][map->py - 1] == 'E')
	{
		if (map->gui_coins == 0)
			finish_game();
		map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px][map->py - 1] = 'X';
		map->py--;
		show_game(map, 0, 0);
		return (1);
	}
	return (0);
}

void	pright(t_game *map)
{
	map->img_player = mlx_xpm_file_to_image(map->mlx, "src/ply.xpm",
			&map->img_width, &map->img_height);
	map->img_epl = mlx_xpm_file_to_image(map->mlx, "src/epr.xpm",
			&map->img_width, &map->img_height);
}

int	map_right(t_game *map)
{
	pright(map);
	if (map->gui_map[map->px][map->py + 1] != 'E' &&
			map->gui_map[map->px][map->py + 1] != '1')
	{
		if (map->gui_map[map->px][map->py + 1] == 'C')
			map->gui_coins--;
		else if (map->gui_map[map->px][map->py + 1] == 'A')
			errors_msg(7);
		if ((map->gui_map[map->px][map->py] == 'X'))
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
		if (map->gui_coins == 0)
			finish_game();
		map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px][map->py + 1] = 'X';
		map->py++;
		mlx_clear_window(map->mlx, map->mlx_win);
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
		else if (map->gui_map[map->px + 1][map->py] == 'A')
			errors_msg(7);
		if ((map->gui_map[map->px][map->py] == 'X'))
			map->gui_map[map->px][map->py] = 'E';
		else
			map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px + 1][map->py] = 'P';
		map->px++;
		mlx_clear_window(map->mlx, map->mlx_win);
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
		mlx_clear_window(map->mlx, map->mlx_win);
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
		else if (map->gui_map[map->px - 1][map->py] == 'A')
			errors_msg(7);
		if ((map->gui_map[map->px][map->py] == 'X'))
			map->gui_map[map->px][map->py] = 'E';
		else
			map->gui_map[map->px][map->py] = '0';
		map->gui_map[map->px - 1][map->py] = 'P';
		map->px--;
		mlx_clear_window(map->mlx, map->mlx_win);
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
		mlx_clear_window(map->mlx, map->mlx_win);
		show_game(map, 0, 0);
		return (1);
	}
	return (0);
}
