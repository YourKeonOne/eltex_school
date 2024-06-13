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
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = SIZE;
    attr.mq_curmsgs = 0;

    mq = mq_open(QUEUE_NAME, O_RDONLY | O_WRONLY);
    if(mq == -1){
       perror("mq_open == -1");
       exit(1);
    }
    
    printf("Клиент | Подключение к серверу\n");
    
    printf("Клиент | Отправляем сообщение серверу\n");
    mq_send(mq, "Hi!", sizeof("Hi!"), 0);

    //sleep(1);

    char buffer[SIZE];
    mq_receive(mq, buffer, sizeof(buffer), NULL); // чот не хочет принимать сообщение нормально
    printf("Клиент | Полученное сообщение: %s\n", buffer);

    mq_close(mq);

    return 0;
}
