#include <stdio.h>

#define MAX_HEIGHT 5
#define MAX_WIDTH 6

typedef struct {
    int height;
    int width;
    char tab[MAX_HEIGHT][MAX_WIDTH];
    int coin;
    int exit;
} t_tools;

int	valid_path1(t_tools *map, int y, int x);
void	valid_path_recursive(t_tools *map, int y, int x);

void	valid_path_recursive(t_tools *map, int y, int x)
{
	valid_path1(map, y, x - 1);
	valid_path1(map, y, x + 1);
	valid_path1(map, y + 1, x);
	valid_path1(map, y - 1, x);
}

int	valid_path1(t_tools *map, int y, int x)
{
	if (map->tab[y][x] == 'P')
	{
		map->tab[y][x] = '1';
		valid_path_recursive(map, y, x);
	}
	else if (map->tab[y][x] == 'E')
	{
		map->exit--;
		map->tab[y][x] = '1';
		valid_path_recursive(map, y, x);
	}
	else if (map->tab[y][x] == '0')
	{
		map->tab[y][x] = '1';
		valid_path_recursive(map, y, x);
	}
	else if (map->tab[y][x] == 'C')
	{
		map->coin--;
		map->tab[y][x] = '1';
		valid_path_recursive(map, y, x);
	}
	if (map->coin == 0 && map->exit == 0)
			return (0);
	return (1);
}
int main() {
    t_tools map = {
        .height = 5,
        .width = 6,
        .tab = {
            {'1', '1', '1', '1', '1', '1'},
            {'1', '1', '1', 'C', '1', '1'},
            {'1', 'P', 'C', 'C', '0', 'E'},
            {'1', '0', '1', '1', '1', '1'},
            {'1', '0', '1', '1', '1', '0'}
        },
        .coin = 3,
        .exit = 1
    };

    printf("Map before applying valid_path algorithm:\n");
    for (int i = 0; i < map.height; ++i) {
        for (int j = 0; j < map.width; ++j) {
            printf("%c ", map.tab[i][j]);
        }
        printf("\n");
    }

    // Apply valid_path algorithm from starting position (y = 1, x = 0)
    if (valid_path1(&map, 2, 1))
	{
		printf("NoN");
		// return 0;
	}
    printf("\nMap after applying valid_path algorithm:\n");
    for (int i = 0; i < map.height; ++i) {
        for (int j = 0; j < map.width; ++j) {
            printf("%c ", map.tab[i][j]);
        }
        printf("\n");
    }

    return 0;
}
