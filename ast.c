//
// Created by suvaditya on 4/15/23.
//

#include "ast.h"

#include "util.h"

#include <stdlib.h>

struct Node *mknode(enum NodeType type, struct Node *left, struct Node *right,
                    int value) {
    struct Node *n = alloc(sizeof *n);
    n->type = type;
    n->left = left;
    n->right = right;
    n->value = value;
    return n;
}

struct Node* mkleaf(enum NodeType type, int value) {
    return mknode(type, NULL, NULL, value);
}
