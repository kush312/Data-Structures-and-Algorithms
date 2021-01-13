//
// Created by kush_ on 11/4/2020.
//

#include "stack.h"

Stack *stack_initialize(int typesize, char *typename) {
    Stack *stack = malloc(sizeof(*stack));
    if (stack == NULL)
        return NULL;
    stack->front = NULL;
    stack->rear = NULL;
    stack->stackSize = 0;
    stack->itemsize = typesize;
    stack->type = malloc(strlen(typename));
    strcpy(stack->type, typename);
    return stack;
}


bool stack_push(Stack *stack, void *pElem) {

    if (stack == NULL || pElem == NULL)
        return false;

    SNode *node = malloc(sizeof(*node));
    node->data = malloc(stack->itemsize);
    memcpy(node->data, pElem, stack->itemsize);

    if (stack->stackSize == 0) {
        stack->front = node;
        stack->rear = node;
        node->next = NULL;
        node->prev = NULL;
    } else {
        node->next = NULL;
        node->prev = stack->rear;
        stack->rear->next = node;
        stack->rear = node;
    }
    stack->stackSize++;

}

void *stack_pop(Stack *stack) {

    // If the list is null, return null.
    if (stack == NULL)
        return NULL;

    // Create a temporary node.
    SNode *temp = stack->front;

    // Iterate until we get to the node to be removed.
    for (int i = 0; i < stack->stackSize - 1; i++)
        temp = temp->next;
    if (stack->stackSize == 1) {
        stack->front = NULL;
        stack->rear = NULL;
    } else {
        stack->rear = temp->prev;
        stack->rear->next = NULL;
    }

    // Reduce the size of the linked list by 1.
    stack->stackSize--;

    // Save the data from the node.
    void *data = temp->data;

    // Free the node.
    free(temp);

    // Return the removed node. It is up to the owner to free it.
    return data;
}

void *stack_peek(Stack *stack) {
    if (stack->stackSize == 0)
        return NULL;
    return stack->front->data;
}

int stack_size(Stack *stack) {
    return stack->stackSize;
}

bool stack_contains(Stack *stack, void *pElem) {

    // If the list is null or the element is null, we return -1.
    if (stack == NULL || pElem == NULL)
        return false;
    // Create a temporary node variable and store the first node.
    SNode *temp = stack->front;
    // Iterate through the list until we find the element.
    for (int i = 0; i < stack->stackSize; i++) {
        // Compare the element to the stored data of this node.
        // If the data matches the element, return the index.

        if (memcmp(temp->data, pElem, stack->itemsize) == 0)
            return true;
        // Move to the next list node.
        temp = temp->next;
    }
    // If we get here, the list didn't have the element. Return -1.
    return false;

}


bool stack_destroy(Stack *stack) {
    // If the list is null, we can't destroy it. Return false.
    if (stack == NULL)
        return false;
    // If there are nodes available in the list, free them.
    if (stack->stackSize > 0) {
        // Create a temporary node for holding nodes.
        SNode *current = stack->front;
        SNode *next = NULL;
        // Iterate through all of the nodes.
        for (int i = 0; i < stack->stackSize; i++) {
            // Store a pointer to the next node.
            next = current->next;
            // Free this node's data.
            free(current->data);
            // Free this node.
            free(current);
            // We move to the next node.
            current = next;
        }
    }
    // Free the necessary linked list fields.
    free(stack->type);
    // Free the linked list.
    free(stack);
    // We destroyed the list. Return true.
    return true;

}