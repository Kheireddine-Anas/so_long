/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:24:53 by akheired          #+#    #+#             */
/*   Updated: 2024/04/24 01:13:04 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	nb_len(int n)
{
	int	len;

	len = 0;
	if (n < 1)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	nbr;

	len = nb_len(n);
	str = (char *)malloc(sizeof(char) * (len) + 1);
	if (!str)
		return (NULL);
	*(str + len) = '\0';
	nbr = n;
	while (len--)
	{
		*(str + len) = 48 + nbr % 10;
		nbr /= 10;
	}
	return (str);
}

int	animation(t_game *map)
{
	if (map->loop < 10000)
	{
		map->loop++;
		return (0);
	}
	map->loop = 0;
	if (map->hel == 1)
	{
		map->img_enemy = mlx_xpm_file_to_image
			(map->mlx, "src/exit.xpm", &map->img_width, &map->img_height);
	}
	else if (map->hel == 2)
	{
		map->img_enemy = mlx_xpm_file_to_image
			(map->mlx, "src/ply.xpm", &map->img_width, &map->img_height);
		map->hel = 0;
	}
	mlx_clear_window(map->mlx, map->mlx_win);
	show_game(map, 0, 0);
	map->hel++;
	return (0);
}

void	screen_mv(t_game *map)
{
	mlx_string_put(map->mlx, map->mlx_win,
			20, 20, 0XFFFFFF, "MOVES : ");
	mlx_string_put(map->mlx, map->mlx_win, 90,
			20, 0XFFFFFF, ft_itoa(map->moves));
}