#include <stdio.h>



void fill(int colls, int rows, int m[rows][colls])
{
    int s=1;
    for (int i=0; i<rows; i++)
        {
            for(int j=0; j<colls; j++)
            {
                m[i][j]=s;
                s++;
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
