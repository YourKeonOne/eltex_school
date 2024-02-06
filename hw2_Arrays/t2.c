#include <stdio.h>
#include <stdlib.h>


void fill_arr(int n, int arr[n])
{
    for (int i = 0; i<n; i++)
    {   
        arr[i]=(i+1);      
    }
}

void reverse_arr(int n, int arr[n])
{
    int start=0;
    int end=n-1;
    while (start < end) 
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void arr_output(int n, int arr[n])
{

    for (int i = 0; i<n; i++)
    {   
        printf("%2d", arr[i]);       
    }
    printf("\n");
}


int main()
{   
    int N;
    printf("\n-----------------------------------------------\n");
    printf("Введите размер маcсива: ");
    scanf("%d", &N);
    int array[N];

    fill_arr(N, array);
    printf("\nСодержимое массива до изменения: ");
    arr_output(N, array);
    reverse_arr(N, array);
    printf("\nСодержимое массива после изменения: ");
    arr_output(N, array);
    printf("\n-----------------------------------------------\n");
}