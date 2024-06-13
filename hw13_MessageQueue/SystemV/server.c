#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>
//#include <>

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

    strcpy(msg.mtext, "Hi!");
    msg.mtype = 1;

    msgsnd(msgid, &msg, SIZE, 0);

    msgrcv(msgid, &msg, SIZE, 2, 0);
    printf("Сообщение от клиента: %s\n", msg.mtext);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
