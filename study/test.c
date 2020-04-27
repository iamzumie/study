#include <stdio.h>

#define rows 3
#define col 4

int main() {

    int studentGrades[rows][col] = {
        {1, 3, 4, 6},
        {1, 2, 4, 6},
        {1, 3, 4, 7}
    };

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", studentGrades[i][j]);
        }
        printf("\n");
    }

    return 0;
}