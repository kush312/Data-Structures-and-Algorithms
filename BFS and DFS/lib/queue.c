// A C program to demonstrate linked list based implementation of queue

#include "queue.h"

Queue *queue_initialize(int typesize, char *typename) {
    Queue *queue = malloc(sizeof(*queue));
    if (queue == NULL)
        return NULL;
    queue->front = NULL;
    queue->rear = NULL;
    queue->queueSize = 0;
    queue->itemsize = typesize;
    queue->type = malloc(strlen(typename));
    strcpy(queue->type, typename);
    return queue;
}


bool queue_enqueue(Queue *queue, void *pElem) {

    //If the list or element are null, return false.
    if (queue == NULL || pElem == NULL)
        return false;

    // Create a new node and populate its data.
    QNode *node = malloc(sizeof(*node));
    node->data = malloc(queue->itemsize);
    memcpy(node->data, pElem, queue->itemsize);

    // If we haven't added any nodes yet, we need to
    // ensure both the first and last are updated.
    if (queue->queueSize == 0) {
        queue->front = node;
        queue->rear = node;
        node->next = NULL;
        node->prev = NULL;
    }
        // If we are adding on the end of the list,
        // we only need to deal with the last pointer.
    else {
        node->next = NULL;
        node->prev = queue->rear;
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->queueSize++;
}

void *queue_dequeue(Queue *queue) {

    // If the list is null, return null.
    if (queue == NULL)
        return NULL;

    // Create a temporary node.
    QNode *temp = queue->front;

    // Iterate until we get to the node to be removed.
    for (int i = 0; i < 0; i++)
        temp = temp->next;

    if (queue->queueSize == 1) {
        queue->front = NULL;
        queue->rear = NULL;
    }else{
        queue->front = temp->next;
        queue->rear->prev = NULL;
    }

    // Reduce the size of the linked list by 1.
    queue->queueSize--;

    // Save the data from the node.
    void *data = temp->data;

    // Free the node.
    free(temp);

    // Return the removed node. It is up to the owner to free it.
    return data;

}

void *queue_peek(Queue *queue) {
    if(queue->queueSize==0)
        return NULL;
    return queue->front->data;
}

int queue_size(Queue *queue) {

    return queue->queueSize;

}

bool queue_contains(Queue *queue, void *pElem) {

    // If the list is null or the element is null, we return -1.
    if (queue == NULL || pElem == NULL)
        return false;
    // Create a temporary node variable and store the first node.
    QNode *temp = queue->front;
    // Iterate through the list until we find the element.
    for (int i = 0; i < queue->queueSize; i++) {
        // Compare the element to the stored data of this node.
        // If the data matches the element, return the index.
        if (memcmp(temp->data, pElem, queue->itemsize) == 0)
            return true;

        // Move to the next list node.
        temp = temp->next;
    }
    // If we get here, the list didn't have the element. Return -1.
    return false;
}

bool queue_destroy(Queue *queue) {
    // If the list is null, we can't destroy it. Return false.
    if (queue == NULL)
        return false;

    // If there are nodes available in the list, free them.
    if (queue->queueSize > 0) {
        // Create a temporary node for holding nodes.
        QNode *current = queue->front;
        QNode *next = NULL;

        // Iterate through all of the nodes.
        for (int i = 0; i < queue->queueSize; i++) {
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
    free(queue->type);

    // Free the linked list.
    free(queue);

    // We destroyed the list. Return true.
    return true;

}