//
// Created by suvaditya on 4/15/23.
//

#include "scanner.h"

static bool putback(struct Scanner *scanner, char ch) {
    if (scanner->top < MAX_PUTBACK) {
        scanner->putback[++scanner->top] = ch;
        return true;
    }
    fprintf(stderr, "putback('%c') failed.\n", ch);
    fflush(stderr);
    exit(1);
}

static int next(struct Scanner *scanner) {
    int ch;
    if (scanner->top < MAX_PUTBACK && scanner->top >= 0) {
        ch = (int)scanner->putback[scanner->top--];
    } else {
        ch = getc(scanner->fp);
    }
    if (ch == '\n') {
        scanner->line++;
    }
    return ch;
}

static int skip_spaces(struct Scanner *scanner) {
    int ch;
    do {
        ch = next(scanner);
    } while (isspace(ch));
    return ch;
}

void scanner_init(struct Scanner *scanner, FILE *fp) {
    scanner->fp = fp;
    scanner->top = -1;
    scanner->line = 0;
    putback(scanner, '\n');
}

static int scan_int(struct Scanner *scanner, int ch) {
    int val = 0;
    while ('0' <= ch && ch <= '9') {
        val = val * 10 + ch - '0';
        ch = next(scanner);
    }
    putback(scanner, (char)ch);
    return val;
}

bool scanner_next(struct Scanner *scanner, struct token *token) {
    int ch;
    ch = skip_spaces(scanner);
    token->value = EOF;
    token->type = T_EOF;
    if (isdigit(ch)) {
        token->type = T_INTLIT;
        token->value = scan_int(scanner, ch);
        return true;
    }
    switch (ch) {
    case EOF:
        return false;
    case '+':
        token->type = T_PLUS;
        break;
    case '-':
        token->type = T_MINUS;
        break;
    case '*':
        token->type = T_STAR;
        break;
    case '/':
        token->type = T_SLASH;
        break;
    default:
        fprintf(stderr,
                "Unrecognized character '%c' on line %zd\n",
                ch,
                scanner->line);
        exit(1);
    }
    return true;
}
