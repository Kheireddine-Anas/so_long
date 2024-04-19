#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif
#include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_str(int fd, char *lft_str);
size_t	ft_strlen(char *s);
int		find_new_line(char *str);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_first_line(char *left_str);
char	*ft_last_line(char *left_str);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char *str);
void	ft_strncpy(char *dst, char *src, int len);

#endif