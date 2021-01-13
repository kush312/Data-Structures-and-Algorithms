//
// Created by kush_ on 11/4/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <string.h>

#ifndef LAB6_STACK_H
#define LAB6_STACK_H

typedef struct SNode {
    void *data;
    struct SNode* next;
    struct SNode* prev;
}SNode;

// The queue, front stores the front node of LL and rear stores the
// last node of LL
typedef struct Stack {
    SNode *front, *rear;
    int itemsize;
    int stackSize;
    char *type;
}Stack;

Stack *stack_initialize(int , char*);

bool stack_push(Stack *, void *);
void *stack_pop(Stack *);
void *stack_peek(Stack*);
int stack_size(Stack*);
bool stack_contains(Stack *, void *);
bool stack_destroy(Stack*);


#endif //LAB6_STACK_H
