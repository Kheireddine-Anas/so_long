#include <stdio.h>

int bordersContainOne(char **str) {
    int rows = 0, cols = 0;
    while (str[rows]) {
        int col = 0;
        while (str[rows][col] != '\0')
            col++;
        if (col > cols)
            cols = col;
        rows++;
    }

    int j = 0;
    while (j < cols) {
        if (str[0][j] != '1' || str[rows - 1][j] != '1')
            return 0;
        j++;
    }

    int i = 0;
    while (i < rows) {
        if (str[i][0] != '1' || str[i][cols - 1] != '1')
            return 0;
        i++;
    }
    return 1;
}

int main() {
    // Example 2D array (3x3)
    char *str[] = {"1111111", "1000001", "1111111", NULL};

    // Check if all borders contain '1'
    if (bordersContainOne(str)) {
        printf("All borders contain '1'\n");
    } else {
        printf("Not all borders contain '1'\n");
    }

    return 0;
}
