#include <stdio.h>
#include <stdlib.h>
#include "isValid.h" 
#include <dlfcn.h>

int main(){
	int *lib_handle;
	int (*operation)(int, int);
	int choise=-1;
	float a,b = 0;
	float result=0;
	int flag=0;

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
			lib_handle = dlopen("./hw8.2_PluginCalc/libplus.so", RTLD_LAZY);
			break;
		case 2:
			system("clear");
			lib_handle = dlopen("./hw8.2_PluginCalc/libminus.so", RTLD_LAZY);
			break;
		case 3:
			system("clear");
			lib_handle = dlopen("./hw8.2_PluginCalc/libmultiply.so", RTLD_LAZY);
			//printf("%g * %g = %g\n", a, b, multiply(a, b));
			break;
		case 4:
			system("clear");
			lib_handle = dlopen("./hw8.2_PluginCalc/libdivide.so", RTLD_LAZY);
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
	if (!lib_handle){
		system("clear");
		fprintf(stderr, "Не получилось подгрузить плагин! %s\n", dlerror());
		exit(1);	
	}

	if(choise==1){
		dlsym(lib_handle, "plus");
	}else if(choise==2){
		dlsym(lib_handle, "minus");
	}else if(choise==3){
		dlsym(lib_handle, "multiply");
	}else if(choise==4){
		dlsym(lib_handle, "divide");
	}
	
	if(operation){
	        printf("Результат: %d\n", operation(a, b));
	}else{
		fprintf(stderr, "Ошибка! %s\n", dlerror());
		dlclose(lib_handle);
	}
	
	dlclose(lib_handle);
	return 0;
}
