#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

struct abonent {
    char name[10];
    char second_name[10];
    char tel[10];
};

// Функция, которая будет очищать память и выходе из программы
void clear(struct abonent **cntct) 
{
	free(*cntct);
}
//-------------------------------------------------------------------------------------------

void add_contact(int *c, struct abonent **cntct)
{
	// При условии, что колличество записей в справочнике <100, пересоздаём массив, иначе - возвращаемся в main
	if (*c <= 100) { 
				(*c)++;
				*cntct=realloc(*cntct,*c * sizeof(struct abonent));
            } else {
                printf("Cправочник переполнeн");
				return;
            }
	// -------------------------------------------------------------------------------		
	
	// Обращаемся к каждому элементу через count - 1, так как сверху мы уже добавили единицу
	printf("\nВведите имя: ");
    scanf("%s", (*cntct)[*c-1].name);
	
    printf("Введите фамилию: ");
    scanf("%s", (*cntct)[*c-1].second_name);
	
    printf("Введите телефон: ");
     scanf("%s", (*cntct)[*c-1].tel);
	// --------------------------------------------------------------------------------------
}


void delete_contact(int *c, struct abonent **cntct)
{
	// Возвращаемся в main, если справочник пуст
	if (*c<1){
			printf("Справочник пуст!");
			return;
	}
	//---------------------------------------------
	
	int contact_number=0;
	printf("Введите номер абонента, которого нужно удалить");
	scanf("%d", &contact_number);
	
	//Если номер записи меньше нуля или больше колличества записей, имеющихся в справочнике, возвращаемся в main
	if((contact_number<0) || (contact_number>*c)){
			printf("Указан неправильный номер абонента!");
			return;
	}
	//--------------------------------
	
	//Цикл, который будет двигать элементы влево
	for (int i= contact_number - 1; i<=*c-1;i++){
			strcpy((*cntct)[i].name, (*cntct)[i+1].name);
			strcpy((*cntct)[i].second_name, (*cntct)[i+1].second_name);
			strcpy((*cntct)[i].tel, (*cntct)[i+1].tel);
	}
	// --------------------------------------------------
	
	*c-=1;
	*cntct=realloc(*cntct,*c * sizeof(struct abonent));
}

void search_contact(int *c, struct abonent **cntct)
{
	char searchName[10];
    printf("\nВведите номер контакта для поиска: ");
    scanf("%s", searchName);
    int search = 0;
	
	for (int i = 0; i < (*c); i++) {
         if (strcmp((*cntct)[i].name, searchName) == 0) {
             search = 1;
             printf("Имя: %s, Фамилия: %s, Телефон: %s\n", (*cntct)[i].name, (*cntct)[i].second_name, (*cntct)[i].tel);
         }
	}
    if (!search) {
        printf("\nАбонент с именем %s не найден\n", searchName);
    }	
}

void show_all_contacts(int *c, struct abonent **cntct)
{
		printf("\nСписок всех абонентов:\n");
            for (int i = 0; i < (*c); i++) {
                printf("Номер контакта: %d, Имя: %s, Фамилия: %s, Телефон: %s\n", i+1, (*cntct)[i].name, (*cntct)[i].second_name, (*cntct)[i].tel);
            }
}



int main() {
    struct abonent* contacts=(struct abonent*) malloc(0);
	if (contacts == NULL){
			exit;
	}
	
    int input = -1, count = 0;
	
    while (1) {
        printf("\n1) Добавить абонента\n");
        printf("2) Удалить абонента\n");
        printf("3) Поиск абонетов по имени\n");
        printf("4) Вывод всех записей\n");
        printf("5) Выход\n");
        printf("Выберите пункт: ");
        scanf("%d", &input);
        switch (input){
        case 1:
            add_contact(&count, &contacts);
            break;
        case 2:
            delete_contact(&count, &contacts);
            break;
        case 3:
            search_contact(&count, &contacts);
            break;
        case 4:
			show_all_contacts(&count, &contacts);
            break;
        case 5:
			clear(&contacts);
            return 0;
            break;
        default:
            printf("Неизвестная команда");
            break;
        }
    }
	
	
    return 0;
}
