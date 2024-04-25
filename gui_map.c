/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:21:42 by akheired          #+#    #+#             */
/*   Updated: 2024/04/25 12:07:22 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pleft(t_game *map)
{
	map->img_player = mlx_xpm_file_to_image(map->mlx, "src/ply_left.xpm",
			&map->img_width, &map->img_height);
	map->img_epl = mlx_xpm_file_to_image(map->mlx, "src/epl.xpm",
			&map->img_width, &map->img_height);
}

void	pright(t_game *map)
{
	map->img_player = mlx_xpm_file_to_image(map->mlx, "src/ply.xpm",
			&map->img_width, &map->img_height);
	map->img_epl = mlx_xpm_file_to_image(map->mlx, "src/epr.xpm",
			&map->img_width, &map->img_height);
}

void	show_game(t_game *map, int i, int j)
{
	mlx_clear_window(map->mlx, map->mlx_win);
	while (map->gui_map[i])
	{
		j = 0;
		while (map->gui_map[i][j])
		{
			if (map->gui_map[i][j] == 'P')
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->img_player, (j * 32), (i * 32));
			else if (map->gui_map[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->img_coins, (j * 32), (i * 32));
			else if (map->gui_map[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->img_wall, (j * 32), (i * 32));
			else if (map->gui_map[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->img_exit, (j * 32), (i * 32));
			else if (map->gui_map[i][j] == 'X')
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->img_epl, (j * 32), (i * 32));
			j++;
		}
		i++;
	}
}

int	keys(int key, t_game *gui_map)
{
	int	check;

	check = 0;
	if (key == 53)
		close_win(gui_map);
	else if (key == KEY_L || key == KEY_A)
		check = map_left(gui_map);
	else if (key == KEY_R || key == KEY_D)
		check = map_right(gui_map);
	else if (key == KEY_DW || key == KEY_S)
		check = map_down(gui_map);
	else if (key == KEY_U || key == KEY_W)
		check = map_up(gui_map);
	if (check)
	{
		gui_map->moves++;
		write(1, "Moves : ", 9);
		show_moves(gui_map->moves);
		write(1, "\n", 1);
	}
	return (0);
}

int	close_win(t_game *map)
{
	(void)map;
	exit(0);
}
