#include "so_long.h"

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	*str_line;
	char	**cp_map;
	char	**gui_map;
}	t_game;

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
	str = malloc(sizeof(char) * (ft_strlen(s1)+ ft_strlen(s1)) + 1);
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

void	map_checker(t_game *map)
{
	int	i;
	int	j;
	int	raw;
	int	col;
	int	rmb;
	
	i = 0;
	while (map->cp_map[i])
	{
		j = 0;
		col = 0;
		while (map->cp_map[i][j])
		{
			j++;
			col++;
		}
		if (i == 0)
			rmb = col;
		if (col != rmb)
		{
			write(1, "Error\nLenght\n", 14);
			exit(1);
		}
		i++;
		raw++;
	}
	if (raw == rmb)
	{
		write(1, "Error\nRectangle Map", 20);
		exit(1);
	}
}
int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	t_game	*map;
	char	*line;

	i = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 7);
		exit(1);
	}
	while (argv[1][i])
		i++;
	if (!(argv[1][i - 5]) || argv[1][i - 4] != '.' || argv[1][i - 3] != 'b' || argv[1][i - 2] != 'e' || argv[1][i - 1] != 'r')
	{
		write(1, "Error\n", 7);
		write(1, "Map Extention .ber\n", 20);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	map = ft_calloc(1, sizeof(t_game));
	if (fd == -1)
	{
		write(1, "Error\n", 7);
		write(1, "Opening file\n", 14);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line && (line[0] == '\0' || line[0] == '\n'))
			exit(1);
		map->str_line = line_con(map->str_line, line);
		map->str_line = line_con(map->str_line, " ");
		if (!line)
			break;
		free(line);
	}
	map->cp_map = ft_split(map->str_line);
	map_checker(map);
}
