#include <stdio.h>

// Function to check if all borders of a 2D array contain '1'
int bordersContainOne(char **str) {
    // Determine the number of rows and columns
    int rows = 0;
    int cols = 0;
    while (str[rows] != NULL) {
        int col = 0;
        while (str[rows][col] != '\0') {
            col++;
        }
        if (col > cols) {
            cols = col;
        }
        rows++;
    }

    // Check top and bottom rows
    for (int j = 0; j < cols; ++j) {
        if (str[0][j] != '1' || str[rows - 1][j] != '1') {
            return 0; // Not all borders contain '1'
        }
    }

    // Check left and right columns
    for (int i = 0; i < rows; ++i) {
        if (str[i][0] != '1' || str[i][cols - 1] != '1') {
            return 0; // Not all borders contain '1'
        }
    }

    // All borders contain '1'
    return 1;
}

int main() {
    // Example 2D array (3x3)
    char *str[] = {"1111111", "100001", "1111111"};

    // Check if all borders contain '1'
    if (bordersContainOne(str)) {
        printf("All borders contain '1'\n");
    } else {
        printf("Not all borders contain '1'\n");
    }

    return 0;
}
