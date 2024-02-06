#include <stdio.h>



void change_byte(int *num, int new_byte){

	unsigned char *byte_Ptr=(unsigned char*)num+2;

	*byte_Ptr = new_byte;

}


void print_bin(int number){
	printf("Бинарное представление: ");
	int flag = 32;
	while (flag > 0){
		printf("%d", (number & 0x100000000) ? 1 : 0);
		number <<= 1;
		flag--;
	}
	printf("\n");
}


int main(){

	int number;
	int byte;
	printf("Введите число: ");
	scanf("%d", &number);
	printf("Введите число для замены третьего байта: ");
	scanf("%d", &byte);

	print_bin(number);
	change_byte(&number, byte);

	printf("Измененное число: %d\n", number);


	print_bin(number);


	return 0;
}
