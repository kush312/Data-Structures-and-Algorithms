//
// Created by kush_ on 11/2/2020.
//


#ifndef LAB6_QUEUE_H
#define LAB6_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct QNode {
    void *data;
    struct QNode* next;
    struct QNode* prev;
}QNode;

// The queue, front stores the front node of LL and rear stores the
// last node of LL
typedef struct Queue {
    QNode *front, *rear;
    int itemsize;
    int queueSize;
    char *type;
}Queue;

Queue *queue_initialize(int , char *);
bool queue_enqueue(Queue *, void *);
void *queue_dequeue(Queue *);
void *queue_peek(Queue *);
int queue_size(Queue *);
bool queue_contains(Queue *, void *);
bool queue_destroy(Queue *);


#endif //LAB6_QUEUE_H
