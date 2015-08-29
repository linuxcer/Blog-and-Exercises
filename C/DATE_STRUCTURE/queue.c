/*************************************************************************
 *  --------->    FILE: queue.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 08/29/2015    TIME:11:40:58
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 20
#define true 1
#define false 0
typedef int bool;

typedef struct queue {
    int p[MAXSIZE];
    int front;
    int rear;
} Queue;

void InitQueue(Queue *q) {
    q->front = q->rear = 0;
}

bool EnQueue(Queue *q, int value) {
    // queue has been fulled
    if ((q->rear + 1) % MAXSIZE == q->front) {
        return false;
    } else {
        q->p[q->rear] = value;
        q->rear = (q->rear + 1) % MAXSIZE;
        return true;
    }
}

bool OutQueue(Queue *q, int *value) {
    // queue is empty
    if (q->rear == q->front) {
        return false;
    } else {
        *value = q->p[q->front];
        q->front = (q->front+ 1) % MAXSIZE;
        return true;
    }
}

int main() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    InitQueue(queue);
    EnQueue(queue, 2);
    EnQueue(queue, 4);
    EnQueue(queue, 9);
    int out;
    OutQueue(queue, &out);
    printf("%d\n", out);
    OutQueue(queue, &out);
    printf("%d\n", out);
    return 0;
}










