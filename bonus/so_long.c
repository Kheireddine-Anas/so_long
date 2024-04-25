/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:10:52 by akheired          #+#    #+#             */
/*   Updated: 2024/04/25 10:42:50 by akheired         ###   ########.fr       */
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
				errors_msg(8);
			j++;
		}
		i++;
	}
}

void	map_check(t_game *map)
{
	while (map->cp_map[map->line - 1][map->length])
		map->length++;
	borders_check(map);
	elements_check(map, 0, 0);
	elements_check_num(map);
	map->gui_coins = map->coins;
	if (path_check(map, map->px, map->py))
		errors_msg(4);
}

void	gui_game(t_game *gui_map)
{
	gui_map->mlx = mlx_init();
	gui_map->mlx_win = mlx_new_window(gui_map->mlx, (gui_map->length * 32),
			(gui_map->line * 32), "so_long");
	gui_map->img_coins = mlx_xpm_file_to_image(gui_map->mlx, "src/coin.xpm",
			&gui_map->img_width, &gui_map->img_height);
	gui_map->img_player = mlx_xpm_file_to_image(gui_map->mlx, "src/ply.xpm",
			&gui_map->img_width, &gui_map->img_height);
	gui_map->img_wall = mlx_xpm_file_to_image(gui_map->mlx, "src/wall.xpm",
			&gui_map->img_width, &gui_map->img_height);
	gui_map->img_exit = mlx_xpm_file_to_image(gui_map->mlx, "src/exit.xpm",
			&gui_map->img_width, &gui_map->img_height);
	gui_map->img_epl = mlx_xpm_file_to_image(gui_map->mlx, "src/epl.xpm",
			&gui_map->img_width, &gui_map->img_height);
	gui_map->img_enemy = mlx_xpm_file_to_image(gui_map->mlx, "src/fire1.xpm",
			&gui_map->img_width, &gui_map->img_height);
	if (!(gui_map->img_coins) || !(gui_map->img_wall)
		|| !(gui_map->img_exit) || !(gui_map->img_player)
		|| !(gui_map->img_enemy) || !(gui_map->img_epl))
		errors_msg(6);
	show_game(gui_map, 0, 0);
	mlx_key_hook(gui_map->mlx_win, keys, gui_map);
	mlx_hook(gui_map->mlx_win, 17, 0, close_win, gui_map);
	mlx_loop_hook(gui_map->mlx, fire_ani, gui_map);
	mlx_loop(gui_map->mlx);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*map;
	char	*line;

	args_exe(argc, argv);
	fd = open(argv[1], O_RDONLY);
	map = ft_calloc(1, sizeof(t_game));
	if (fd == -1)
		errors_msg(5);
	while (1)
	{
		line = get_next_line(fd);
		if (line && (line[0] == '\0' || line[0] == '\n'))
			errors_msg(3);
		map->str_line = line_con(map->str_line, line);
		if (!line)
			break ;
		free(line);
		map->line++;
	}
	map->cp_map = ft_split(map->str_line, '\n');
	map->gui_map = ft_split(map->str_line, '\n');
	map_check(map);
	gui_game(map);
}
