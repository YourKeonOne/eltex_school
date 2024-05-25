#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define max_cmd_length 100

int main() {
	
    char command[max_cmd_length];
    pid_t pid, ppid;
	
    while (1) {
        printf("\nВведите команду. exit, чтобы выйти: ");
        fgets(command, max_cmd_length, stdin);
        command[strcspn(command, "\n")] = '\0';
		
		
		
        if (strcmp(command, "exit") == 0) {
            printf("Выход.\n");
            break;
        }
        
        switch (pid=fork()) {
	case -1:
		perror("fork == -1");
		exit(1);
		break;
	case 0:  // Дочерний процесс
		printf("\n|Дочерний| pid = %d \n\n", getpid());
		execlp("/bin/sh", "sh", "-c", command, (char *) NULL);
		perror("execlp");
		exit(1);
        	break;
        default:  // Родительский процесс
		wait(NULL);
		printf("\n|Родитель| ppid = %d\n\n", getpid());
	break;
        }
		printf("\n######################################\n");
    }
    
    return 0;
}
