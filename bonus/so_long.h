#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif
#include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

# define KEY_L 123
# define KEY_R 124
# define KEY_DW 125
# define KEY_U 126

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*img_wall;
	void	*img_exit;
	void	*img_player;
	void	*img_coins;
	void	*img_enemy;
	int		img_width;
	int		img_height;
	char	*str_line;
	char	**cp_map;
	char	**gui_map;
	int		line;
	int		length;
	int		player;
	int		enemys;
	int		px;
	int		py;
	int		coins;
	int		gui_coins;
	int		exit;
	int		moves;
	int		loop;
	int		hel;
}	t_game;

char	*get_next_line(int fd);
char	*read_str(int fd, char *lft_str);
size_t	ft_strlen(char *s);
int		find_new_line(char *str);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_first_line(char *left_str);
char	*ft_last_line(char *left_str);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *str, char c);
char	*ft_itoa(int n);
char	*line_con(char *s1, char *s2);
void	args_exe(int argc, char **argv);
void	borders_check(t_game *map);
int		path_check(t_game *map, int x, int y);
void	errors_msg(int msg_num);
void	show_game(t_game *map, int i, int j);
void	elements_check(t_game *map, int i, int j);
void	elements_check_num(t_game *map);
void	path_check_recursive(t_game *map, int x, int y);
void	show_moves(int nbr);
void	screen_mv(t_game *map);
int		path_check(t_game *map, int x, int y);
int		keys(int key, t_game *gui_map);
int		map_left(t_game *gui_map);
int		map_right(t_game *gui_map);
int		map_down(t_game *gui_map);
int		map_up(t_game *gui_map);
int		close_win(t_game *map);
int	animation(t_game *map);

#endif