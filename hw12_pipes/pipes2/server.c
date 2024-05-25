#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 3

int main() {

    mkfifo("pipe", 0666);
    
    int descriptor = open("pipe", O_WRONLY);
    write(descriptor, "Hi!", SIZE);
    close(descriptor);
    
    return 0;
}
