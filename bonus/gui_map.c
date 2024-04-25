/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:21:42 by akheired          #+#    #+#             */
/*   Updated: 2024/04/25 12:07:06 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_win(t_game *map, void *img_item, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		img_item, (j * 32), (i * 32));
}

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
				img_win(map, map->img_player, i, j);
			else if (map->gui_map[i][j] == 'C')
				img_win(map, map->img_coins, i, j);
			else if (map->gui_map[i][j] == '1')
				img_win(map, map->img_wall, i, j);
			else if (map->gui_map[i][j] == 'E')
				img_win(map, map->img_exit, i, j);
			else if (map->gui_map[i][j] == 'A')
				img_win(map, map->img_enemy, i, j);
			else if (map->gui_map[i][j] == 'X')
				img_win(map, map->img_epl, i, j);
			j++;
		}
		i++;
	}
	screen_mv(map);
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
		gui_map->moves++;
	return (0);
}
