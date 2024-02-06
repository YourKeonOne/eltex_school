#include <stdio.h>
#include <string.h>

#define SIZE 100

struct abonent {
    char name[10];
    char second_name[10];
    char tel[10];
};

void add_user(int *c, struct  abonent *usrs)
{
	if (*c <= 100) {
                printf("\nВведите имя: ");
                scanf("%10s", usrs[*c].name);
                printf("Введите фамилию: ");
                scanf("%10s", usrs[*c].second_name);
                printf("Введите телефон: ");
                scanf("%10s", usrs[*c].tel);
                (*c)++;
            } else {
                printf("Cправочник переполнeн");
            }
}

void delete_user(int *c, struct abonent *usrs)
{
	char nameToDelete[10];
				printf("\nВведите имя для удаления: ");
				scanf("%10s", nameToDelete);
				int delete = 0;
				for (int i = 0; i < (*c); i++) {
					if (strcmp(usrs[i].name, nameToDelete) == 0) {
						strcpy(usrs[i].name, "0");
						strcpy(usrs[i].second_name, "0");
						strcpy(usrs[i].tel, "0");
						printf("Абонент удален\n");
						delete = 1;
						break;
					}
				}

				if (!delete) {
					printf("\nАбонент с именем %s не найден\n", nameToDelete);
				}	
}

void search_user(int *c, struct abonent *usrs)
{
	char searchName[10];
            printf("\nВведите имя для поиска: ");
            scanf("%10s", searchName);
            int search = 0;
            for (int i = 0; i < (*c); i++) {
                if (strcmp(usrs[i].name, searchName) == 0) {
                    search = 1;
                    printf("Имя: %s, Фамилия: %s, Телефон: %s\n", usrs[i].name, usrs[i].second_name, usrs[i].tel);
                }
            }
            if (!search) {
                printf("\nАбонент с именем %s не найден\n", searchName);
            }	
}

void show_all_users(int *c, struct abonent *usrs)
{
		printf("\nСписок всех абонентов:\n");
            for (int i = 0; i < (*c); i++) {
                printf("Имя: %s, Фамилия: %s, Телефон: %s\n", usrs[i].name, usrs[i].second_name, usrs[i].tel);
            }
}
int main() {
    struct abonent users[SIZE];
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
            add_user(&count, users);
            break;
        case 2:
            delete_user(&count, users);
            break;
        case 3:
            search_user(&count, users);
            break;
        case 4:
			show_all_users(&count, users);
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Неизвестная команда");
            break;
        }
    }

    return 0;
}
