#include <stdio.h>
#include <stdlib.h>
#include "isValid.h"

float isValid(float number) {
    int attempts = 3;
    int success = 0;

    while (attempts > 0) {
        if (scanf("%f", &number) != 1) {
            printf("Неправильное число. Если число десятичное, введите его с точностью до 7-ми знаков, разделитель - точка.\n");
            while(getchar() != '\n');
            attempts--;
			printf("У вас осталось %d попыток\n", attempts);
        } else {
            success = 1;
            printf("Введенное число: %g\n", number);
            return number;
        }
    }

    if (!success) {
        printf("Вы неверно ввели число 3 раза. Выход из калькулятора.\n");
		exit(0);
    }
}
