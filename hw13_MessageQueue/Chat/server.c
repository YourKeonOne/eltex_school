#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>



#define QUEUE_NAME "/chat_queue"
#define MAX_MESSAGE_SIZE 1024
#define MAX_QUEUE_SIZE 10
#define MAX_USERNAME_SIZE 50

typedef struct ChatMessage {
    char username[MAX_USERNAME_SIZE];
    char message[MAX_MESSAGE_SIZE - MAX_USERNAME_SIZE];
} ChatMessage;

int main() {
    mqd_t mq;
    struct mq_attr attr;
    struct ChatMessage msg;
    int flag = 0;

    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_QUEUE_SIZE;
    attr.mq_msgsize = sizeof(ChatMessage);
    attr.mq_curmsgs = 0;

    mq = mq_open(QUEUE_NAME, O_RDONLY | O_CREAT, 0600, &attr);
    if (mq == -1) {
        perror("mq_open == -1");
        return 1;
    }

    printf("Чат запущен..\n");

    while (!flag) {
        ssize_t bytes_read;
        unsigned int sender;

        bytes_read = mq_receive(mq, (char *)&msg, sizeof(ChatMessage), &sender);
        if (bytes_read == -1) {
            perror("mq_receive == -1");
            flag = 1;
        } else {
            printf("%s: %s\n", msg.username, msg.message);
        }
    }

    mq_close(mq);

    return 0;
}
