#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 3

int main() {

    int descriptor = open("pipe", O_RDONLY);
    char message[SIZE];
    read(descriptor, message, sizeof(message));
    printf("%s\n", message);
    close(descriptor);
    
    return 0;
}
