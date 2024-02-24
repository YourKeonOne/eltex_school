#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contacts.h"


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
