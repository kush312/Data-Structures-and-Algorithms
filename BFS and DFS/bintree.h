//
// Created by kush_ on 11/5/2020.
//

#ifndef LAB6_BINTREE_H
#define LAB6_BINTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "lib/queue.h"


typedef struct _BinTreeNode {
    void* data;
    struct _BinTreeNode* left;
    struct _BinTreeNode* right;

} BinaryTreeNode;


typedef struct _BinaryTree {

    BinaryTreeNode *top;
    int itemSize;
    char *type;

    int (*compare)(void *, void *);


    void (*print)(void *);
} BinaryTree;

BinaryTree *bintree_initialize(int, char *, int (*)(void *, void *), void (*)(void *));

BinaryTreeNode *bintree_create_node(int, void *);

bool bintree_insert(BinaryTree *, void *);

bool bintree_search(BinaryTree *, void *);

void bintree_print_in_order(BinaryTree *);

void bintree_print_pre_order(BinaryTree *);

void bintree_print_post_order(BinaryTree *);

void bintree_print_reverse_order(BinaryTree *);

bool _bintree_insert_recursive(BinaryTree *, BinaryTreeNode *, void *);

bool _bintree_search_recursive(BinaryTree *, BinaryTreeNode *, void *);

void _bintree_in_order_recursive(BinaryTree *, BinaryTreeNode *);

void _bintree_pre_order_recursive(BinaryTree *, BinaryTreeNode *);

void _bintree_post_order_recursive(BinaryTree *, BinaryTreeNode *);

void _bintree_reverse_order_recursive(BinaryTree *, BinaryTreeNode *);

void bintree_print_breadth_first(BinaryTree *);

void bintree_print_depth_first(BinaryTree *);


bool bintree_insert_replace(BinaryTree*, void*);

bool _bintree_insert_replace_recursive(BinaryTree*, BinaryTreeNode *, void *);
Queue *queue_initialize(int, char *);

bool queue_enqueue(Queue *, void *);
void *queue_dequeue(Queue *);
bool queue_destroy(Queue *);

#endif //LAB6_BINTREE_H
