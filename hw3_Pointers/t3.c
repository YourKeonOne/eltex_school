#include <stdio.h>



int main(){

	int array[5] = {4, 6, 2, 1, 6};
	printf("Array:%p\t         ", array);
	int *pArray=array;
	printf("\npArray:%p\t      ", pArray);

	int i;

	printf("\n Array: { ");
	for(i=0; i<5; i++){

		printf("%d ", *pArray+i);
	}
	printf("}");

}
