#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>

#define SIZE 128

struct msgbuf {
    long mtype;
    char mtext[SIZE];
};

int main() {
    key_t key = ftok("server-client", 'a');
    int msgid = msgget(key, IPC_CREAT | 0600);//0600 - только создатель очереди имеет право к ней обращаться
    
    if (msgid == -1){// проверить msgget
    	perror("msgid == -1");
    }
    
    struct msgbuf msg;

    msgrcv(msgid, &msg, SIZE, 1, 0);
    printf("Сообщение от сервера: %s\n", msg.mtext);

    strcpy(msg.mtext, "Hello!");
    msg.mtype = 2;

    msgsnd(msgid, &msg, SIZE, 0);

    return 0;
}
