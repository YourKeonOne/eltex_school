#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *file = fopen("output.txt", "a+");
	
	if (file == NULL){
		printf("Ошибка создания файла!\n");
		exit(1);
	}
	
	fprintf(file, "String from file");
	
	fseek(file, 0, SEEK_END);
	int lenght = ftell(file);
	
	for(int i=0; i <= lenght; i++){
		fseek(file, -i, SEEK_END);
        putchar(fgetc(file));
	}
	printf("\n");
	fclose(file);
	return 0;
}
