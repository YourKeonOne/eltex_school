#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 3

int main() {

    int descriptor[2];
	
    if (pipe(descriptor) == -1) {
        perror("Pipe");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork");
        exit(1);
    }
	
    if (pid == 0) {
        close(descriptor[1]); 
        char buffer[SIZE];
        read(descriptor[0], buffer, SIZE); 
        printf("%s\n", buffer); 
        close(descriptor[0]); 
    } else { 
        close(descriptor[0]);
        write(descriptor[1], "Hi!", SIZE);
        close(descriptor[1]);
        wait(NULL);
    }

	return 0;
}