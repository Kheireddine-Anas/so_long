#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 1, j = 0;
	int raw = 0, col, rmb;
	while (argv[i])
	{
		j = 0;
		col = 0;
		while (argv[i][j])
		{
			j++;
			col++;
		}
		if (i == 1)
			rmb = col;
		if (col != rmb)
		{
			printf("NoN");
			return (0);
		}
		i++;
		raw++;
	}
	if (raw == rmb)
		printf("Rectangle Map");
	else
		printf("Yes");
	(void)argc;
}