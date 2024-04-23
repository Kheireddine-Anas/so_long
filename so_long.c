/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:10:52 by akheired          #+#    #+#             */
/*   Updated: 2024/04/23 18:51:19 by akheired         ###   ########.fr       */
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

void	elements_check_num(t_game *map)
{
	if (map->coins < 1 || map->player != 1 || map->exit != 1)
		errors_msg(2);
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

void	map_check(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->cp_map[map->line - 1][map->length])
		map->length++;
	borders_check(map);
	elements_check(map, 0, 0);
	elements_check_num(map);
	map->gui_coins = map->coins;
	if (path_check(map, map->px, map->py))
		errors_msg(4);
}

void	show_game(t_game *map, int i, int j)
{
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
			j++;
		}
		i++;
	}
}

int	keys(int key, t_game *gui_map)
{
	int	check;

	check = 0;
	if (key == KEY_L || key == KEY_A)
	{
		check = map_left(gui_map);
	}
	else if (key == KEY_R || key == KEY_D)
	{
		check = map_right(gui_map);
	}
	else if (key == KEY_DW || key == KEY_S)
	{
		check = map_down(gui_map);
	}
	else if (key == KEY_U || key == KEY_W)
	{
		check = map_up(gui_map);
	}
	if (check)
	{
		gui_map->moves++;
		printf("Moves : %d\n", gui_map->moves);
	}
	return (0);
}

int	close_win(t_game *map)
{
	(void)map;
	exit(0);
}

void	gui_game(t_game *gui_map)
{
	gui_map->mlx = mlx_init();
	gui_map->mlx_win = mlx_new_window(gui_map->mlx, (gui_map->length * 32),
			(gui_map->line * 32), "so_long");
	gui_map->img_coins = mlx_xpm_file_to_image(gui_map->mlx, "coin.xpm",
			&gui_map->img_width, &gui_map->img_height);
	gui_map->img_player = mlx_xpm_file_to_image(gui_map->mlx, "ply.xpm",
			&gui_map->img_width, &gui_map->img_height);
	gui_map->img_wall = mlx_xpm_file_to_image(gui_map->mlx, "wall.xpm",
			&gui_map->img_width, &gui_map->img_height);
	gui_map->img_exit = mlx_xpm_file_to_image(gui_map->mlx, "exit.xpm",
			&gui_map->img_width, &gui_map->img_height);
	show_game(gui_map, 0, 0);
	mlx_key_hook(gui_map->mlx_win, keys, gui_map);
	mlx_hook(gui_map->mlx_win, 17, 0, close_win, gui_map);
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
