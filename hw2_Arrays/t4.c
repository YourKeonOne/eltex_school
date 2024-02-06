#include <stdio.h>



void fill(int cols, int rows, int m[rows][cols])
{
    int value = 1;
    int sRow = 0, eRow = rows - 1;
    int sCol = 0, eCol = cols - 1;

    while (sRow <= eRow && sCol <= eCol) 
    {
        for (int i = sCol; i <= eCol; ++i) 
        {
            m[sRow][i] = value++;
        }
        sRow++;

        for (int i = sRow; i <= eRow; ++i) 
        {
            m[i][eCol] = value++;
        }
        eCol--;

        if (sRow <= eRow) 
        {
            for (int i = eCol; i >= sCol; --i) 
            {
                m[eRow][i] = value++;
            }
            eRow--;
        }

        if (sCol <= eCol)
        {
            for (int i = eRow; i >= sRow; --i) 
            {
                m[i][sCol] = value++;
            }
            sCol++;
        }
    }
}

void matrix_output(int colls, int rows, int m[rows][colls])
{
    printf("Полученная матрица:");
    for (int i=0; i<rows; i++)
    {
        printf("\n");
        for(int j=0; j<colls; j++)
        {   
 
            printf("%5d", m[i][j]);

        }
    }
    printf("\n\n");
} 

int main()
{
    int N;
    printf("Введите размер матрицы: ");
    scanf("%d", &N);
    int ROWS=N;
    int COLLS=N;
    int matrix[ROWS][COLLS];
    fill(COLLS,ROWS,matrix);
    matrix_output(COLLS,ROWS,matrix);
    return 0;
}
