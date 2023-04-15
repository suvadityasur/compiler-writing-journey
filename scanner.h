//
// Created by suvaditya on 4/15/23.
//

#ifndef MINICC_SCANNER_H
#define MINICC_SCANNER_H

#include "token.h"
#include "common.h"

#define MAX_PUTBACK 8

struct Scanner {
    FILE *fp;
    char putback[MAX_PUTBACK];
    size_t line;
    ssize_t top;
};

void scanner_init(struct Scanner *scanner, FILE *fp);
bool scanner_next(struct Scanner* scanner, struct token* token);

#endif //MINICC_SCANNER_H
