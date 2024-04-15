#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	pid_t pid, ppid;
	int status = 0;

	switch(pid=fork()){
		case(-1):
			perror("fork == -1");
			exit(1);
		break;
		case(0):
//			printf("\n--------------Дочерний процесс-----------\n");
			printf("|Дочерний|pid дочернего процесса: %d\n", getpid());
			printf("|Дочерний|pid родительского процесса: %d\n", getppid());
			printf("|Дочерний|Завершение...\n");
			exit(status);
//			printf("---------------------------------------------");
		break;
		default:
//			printf("\n--------------Родительский процесс-----------\n");
			printf("|Родитель|pid дочернего процесса: %d\n", pid);
			printf("|Родитель|pid процесса: %d\n", getpid());
			wait(NULL);
			printf("|Родитель|Код возврата дочернего процесса: %d\n", WEXITSTATUS(status));
			printf("|Родитель|Завершение...\n");
//			printf("---------------------------------------------");
		break;
	}



	return 0;
}
