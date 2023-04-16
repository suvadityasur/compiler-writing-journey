//
// Created by suvaditya on 4/15/23.
//

#ifndef MINICC_AST_H
#define MINICC_AST_H

enum NodeType {
    A_ADD,
    A_SUB,
    A_MUL,
    A_DIV,
    A_INTLIT,
};

struct Node {
    enum NodeType type;
    struct Node *left;
    struct Node *right;
    int value;
};

#endif // MINICC_AST_H
