
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintree.h"

BinaryTree *
bintree_initialize(int typeSize, char *typeName, int (*compFunction)(void *, void *), void (*printFunction)(void *)) {
    // Allocate space for the binary tree.
    BinaryTree *tree = malloc(sizeof(*tree));

    // If the tree cannot be allocated, we return NULL.
    if (tree == NULL)
        return NULL;

    // Set the root node to NULL for a starting tree.
    tree->top = NULL;

    // Store the incoming item size.
    tree->itemSize = typeSize;

    // Allocate enough space for the type name and store it.
    tree->type = malloc(strlen(typeName) + 1);
    strcpy(tree->type, typeName);

    // Store the compare and print functions in our tree.
    tree->compare = compFunction;
    tree->print = printFunction;

    // Return a pointer to the tree.
    return tree;
}

BinaryTreeNode *bintree_create_node(int size, void *element) {
    // Allocate space for the binary tree node.
    BinaryTreeNode *node = malloc(sizeof(*node));

    // If we couldn't allocate the space, return NULL.
    if (node == NULL)

        return NULL;

    // Allocate enough space to hold the data, then copy it in.
    node->data = malloc(size);
    memcpy(node->data, element, size);

    // Set the left and right children of this node to NULL.
    node->left = NULL;
    node->right = NULL;

    // Return a pointer to the node.
    return node;
}

bool bintree_insert(BinaryTree *tree, void *element) {
    // If the tree or element are NULL, return false.
    if (tree == NULL || element == NULL)
        return false;

    // If top is NULL, make a node and store it in top.
    if (tree->top == NULL) {
        // Create a node and store it in top.
        tree->top = bintree_create_node(tree->itemSize, element);

        // If we could not create the node, return false.
        if (tree->top == NULL)
            return false;

        // We've created a node. Return true.
        return true;
    } else {
        // If there is a root node, we can recurse on it and return the result.
        return _bintree_insert_recursive(tree, tree->top, element);
    }
}

bool bintree_search(BinaryTree *tree, void *element) {
    if (tree == NULL || element == NULL)
        return false;

    return _bintree_search_recursive(tree, tree->top, element);
}

void bintree_print_in_order(BinaryTree *tree) {
    if (tree == NULL || tree->top == NULL)
        return;

    _bintree_in_order_recursive(tree, tree->top);

}

void bintree_print_pre_order(BinaryTree *tree) {
    if (tree == NULL || tree->top == NULL)
        return;

    _bintree_pre_order_recursive(tree, tree->top);
}

void bintree_print_post_order(BinaryTree *tree) {
    if (tree == NULL || tree->top == NULL)
        return;

    _bintree_post_order_recursive(tree, tree->top);
}

void bintree_print_reverse_order(BinaryTree *tree) {
    if (tree == NULL || tree->top == NULL)
        return;

    _bintree_reverse_order_recursive(tree, tree->top);
}

bool _bintree_insert_recursive(BinaryTree *tree, BinaryTreeNode *node, void *element) {
    // 1. Compare the node data and the element.
    // 		a. If E <= D, check left.
    // 		b. If  E > D, check right.
    // 2. If checking left and left is null, make a new node and insert.
    //    Otherwise recurse on left.
    // 3. If checking right and right is null, make a new node and insert.
    //    Otherwise recurse on right.

    if (tree->compare(node->data, element) < 0) {
        if (node->left == NULL) {
            node->left = bintree_create_node(tree->itemSize, element);

            if (node->left == NULL)
                return false;

            return true;
        } else {
            return _bintree_insert_recursive(tree, node->left, element);
        }
    } else {
        if (node->right == NULL) {
            node->right = bintree_create_node(tree->itemSize, element);

            if (node->right == NULL)
                return false;

            return true;
        } else {
            return _bintree_insert_recursive(tree, node->right, element);
        }
    }
}

bool _bintree_search_recursive(BinaryTree *tree, BinaryTreeNode *node, void *element) {
    // Compare the node data and the element:
    // 		a. If they are equal, return true.
    // 		b. If E < D, check left. If left is NULL, return false. Otherwise recurse.
    // 		c. If E > D, check right. If right is NULL, return false. Otherwise recurse.

    int comp = tree->compare(node->data, element);

    if (comp == 0)
        return true;
    else if (comp < 0)
        if (node->left == NULL)
            return false;
        else
            return _bintree_search_recursive(tree, node->left, element);
    else if (comp > 0)
        if (node->right == NULL)
            return false;
        else
            return _bintree_search_recursive(tree, node->right, element);
}

void _bintree_in_order_recursive(BinaryTree *tree, BinaryTreeNode *node) {
    // Traverse to the Left.
    if (node->left != NULL)
        _bintree_in_order_recursive(tree, node->left);

    // Print the current node's data.
    tree->print(node->data);

    // Traverse to the Right.
    if (node->right != NULL)
        _bintree_in_order_recursive(tree, node->right);
}

void _bintree_pre_order_recursive(BinaryTree *tree, BinaryTreeNode *node) {
    // Print the current node's data.
    tree->print(node->data);

    // Traverse to the Left.
    if (node->left != NULL)
        _bintree_pre_order_recursive(tree, node->left);

    // Traverse to the Right.
    if (node->right != NULL)
        _bintree_pre_order_recursive(tree, node->right);
}

void _bintree_post_order_recursive(BinaryTree *tree, BinaryTreeNode *node) {
    // Traverse to the Left.
    if (node->left != NULL)
        _bintree_post_order_recursive(tree, node->left);

    // Traverse to the Right.
    if (node->right != NULL)
        _bintree_post_order_recursive(tree, node->right);

    // Print the current node's data.
    tree->print(node->data);
}

void _bintree_reverse_order_recursive(BinaryTree *tree, BinaryTreeNode *node) {
    // Traverse to the Right.
    if (node->right != NULL)
        _bintree_reverse_order_recursive(tree, node->right);

    // Print the current node's data.
    tree->print(node->data);

    // Traverse to the Left.
    if (node->left != NULL)
        _bintree_reverse_order_recursive(tree, node->left);
}

void bintree_print_depth_first(BinaryTree *tree) {
    bintree_print_pre_order(tree);
}


void bintree_print_breadth_first(BinaryTree *tree) {

    Queue *queue = queue_initialize(sizeof(BinaryTreeNode), tree->type);
    BinaryTreeNode *traverse;
    if (tree->top == NULL)
        return;

  //printf("entering the queue:\n");
  queue_enqueue(queue, tree->top);
    //printf("entering after the queue:\n");

    while (queue->queueSize!=0) {
       // printf("inside the if\n");

        traverse = queue_dequeue(queue);

        //printf("storing the deque elements\n");

        tree->print(traverse->data);

        //printf("printing\n");
        if (traverse->left != NULL)
           // printf("left\n");
        queue_enqueue(queue, traverse->left);
        if (traverse->right != NULL)
            queue_enqueue(queue, traverse->right);

    }

    queue_destroy(queue);

}

bool bintree_insert_replace(BinaryTree *tree, void *element) {
    bool flag = false;
    // If the tree or element are NULL, return false.
    if (tree == NULL || element == NULL)
        return false;

    // If top is NULL, make a node and store it in top.
    if (tree->top == NULL) {
        // Create a node and store it in top.
        tree->top = bintree_create_node(tree->itemSize, element);

        // If we could not create the node, return false.
        if (tree->top == NULL)
            return false;

        // We've created a node. Return true.
        return true;

    } else {
        // If there is a root node, we can recurse on it and return the result.
        if (bintree_search(tree, element) == true) {
            flag = true;
        }
        while (flag != true) {
            return _bintree_insert_recursive(tree, tree->top, element);
        }
    }


}

bool _bintree_insert_replace_recursive(BinaryTree *tree, BinaryTreeNode *node, void *element) {

// 1. Compare the node data and the element.
    // 		a. If E <= D, check left.
    // 		b. If  E > D, check right.
    // 2. If checking left and left is null, make a new node and insert.
    //    Otherwise recurse on left.
    // 3. If checking right and right is null, make a new node and insert.
    //    Otherwise recurse on right.

    if (tree->compare(node->data, element) < 0) {
        if (node->left == NULL) {
            node->left = bintree_create_node(tree->itemSize, element);

            if (node->left == NULL)
                return false;

            return true;
        } else {
            return _bintree_insert_recursive(tree, node->left, element);
        }
    } else {
        if (node->right == NULL) {
            node->right = bintree_create_node(tree->itemSize, element);

            if (node->right == NULL)
                return false;

            return true;
        } else {
            return _bintree_insert_recursive(tree, node->right, element);
        }
    }


}




