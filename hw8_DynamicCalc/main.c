#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main(){
	int choise=-1;
	float a,b = 0;
	float result=0;
	int flag=0;

	while(1){
		flag=0;
		printf("1.Сложение\n");
		printf("2.Вычитание\n");
		printf("3.Умножение\n");
		printf("4.Деление\n");
		printf("5.Выход\n");
		printf("\nВыберите операцию: ");	
		scanf("%d", &choise);
		printf("\n");
		
//Устанавливаем флаг. Если флаг = 1, то мы спрашиваем у пользователя значение первой и второй переменной. Флаг обнуляется при каждом обновлении цикла
		for (int i = 1; i<5; i++){
			if (i == choise)
				flag=1;
		}
//----------------------------------------
		
		if (flag==1){
			printf("\nПервое значение: ");
			//scanf("%f", &a);
			a = isValid(a);
			printf("\nВторое значение: ");
			//scanf("%f", &b);
			b = isValid(b);
		}
		
		switch(choise){
			case 1:
				system("clear");
				printf("%g + %g = %g\n", a, b, plus(a,b));
				break;
			case 2:
				system("clear");
				printf("%g - %g = %g\n", a, b, minus(a, b));
				break;
			case 3:
				system("clear");
				printf("%g * %g = %g\n", a, b, multiply(a, b));
				break;
			case 4:
				system("clear");
				printf("%g / %g = %g\n", a, b, divide(a, b));
				break;
			case 5:
				system("clear");
				printf("Выход из калькулятора\n");
				return 0;
				break;
			default:
				system("clear");
				printf("\nНеизвестная операция\n");
				break;
		}
	}
	
	
	return 0;
}