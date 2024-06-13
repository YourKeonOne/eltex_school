#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <unistd.h>
#include <errno.h>

#define QUEUE_NAME "/my_msg_queue"
#define SIZE 1024



int main() {

    mqd_t mq;
    
    struct mq_attr attr;
    attr.mq_flags = 0; /* Flags (ignored for mq_open()) */
    attr.mq_maxmsg = 10;/* Max. # of messages on queue */
    attr.mq_msgsize = SIZE;/* Max. message size (bytes) */
    attr.mq_curmsgs = 0;/* # of messages currently in queue*/

    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, 0666, &attr);
    if(mq == -1){
       perror("mq_open == -1");
       exit(1);
    }
    
    
    char buffer[SIZE];
    
    mq_receive(mq, buffer, sizeof(buffer), NULL);
    printf("Сервер | Получил сообщение: %s\n", buffer);

    printf("Сервер | Отправляем ответ клиенту\n");
    mq_send(mq, "Hello!", sizeof("Hello!"), 0);

    mq_close(mq);
    mq_unlink(QUEUE_NAME);

    return 0;
}
