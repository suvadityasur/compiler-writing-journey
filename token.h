//
// Created by suvaditya on 4/15/23.
//

#ifndef MINICC_TOKEN_H
#define MINICC_TOKEN_H

enum TokenType {
    T_EOF,
    T_PLUS, T_MINUS, T_STAR, T_SLASH,
    T_INTLIT,
    MAX_TOKEN_TYPES
};

struct token {
    enum TokenType type;
    int value;
};

#endif //MINICC_TOKEN_H
