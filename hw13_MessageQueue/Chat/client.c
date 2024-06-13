#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>

#define QUEUE_NAME "/chat_queue"
#define MAX_MESSAGE_SIZE 1024
#define MAX_USERNAME_SIZE 50




typedef struct ChatMessage{
    char username[MAX_USERNAME_SIZE];
    char message[MAX_MESSAGE_SIZE - MAX_USERNAME_SIZE];
}ChatMessage;



int main() {
    mqd_t mq;
    struct ChatMessage msg;

    mq = mq_open(QUEUE_NAME, O_WRONLY);
    if (mq == -1) {
        perror("mq_open == -1");
        return 1;
    }

    printf("Введите ваш юзернейм, который будет отображатсья в чате: ");
    fgets(msg.username, MAX_USERNAME_SIZE, stdin);
    msg.username[strcspn(msg.username, "\n")] = 0;

    printf("Введите сообщение: ");
    while (fgets(msg.message, MAX_MESSAGE_SIZE - MAX_USERNAME_SIZE, stdin)) {
        mq_send(mq, (const char *)&msg, sizeof(msg), 0);
        printf("Введите сообщение: ");
    }

    mq_close(mq);

    return 0;
}
