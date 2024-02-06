#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

char* find_substring(char* string, char* substring) {


	int string_length = strlen(string);
	int substring_length = strlen(substring);

	for (int i = 0; i <= string_length - substring_length; i++) {

		int j;

		for (j = 0; j < substring_length; j++) {

			if (string[i + j] != substring[j]){

				 break;
			}
		}

		if (j == substring_length){

		return &string[i];

		}
	}

	return NULL;
}

int main() {

	char string[MAX_LENGTH];
	char substring[MAX_LENGTH];

	printf("Введите строку: ");
	fgets(string, sizeof(string), stdin);

	printf("Введите подстроку: ");
	fgets(substring, sizeof(substring), stdin);


	string[strcspn(string, "\n")] = '\0';
	substring[strcspn(substring, "\n")] = '\0';

	char* result = find_substring(string, substring);


	printf("Позиция: %ld\n", result - string);

	return 0;
}
