/**
 * Based on https://github.com/DoctorWkt/acwj
 */

#include "scanner.h"

#include <stdio.h>

static char const *tokstr[MAX_TOKEN_TYPES] = {
    [T_PLUS] = "+",
    [T_MINUS] = "-",
    [T_STAR] = "*",
    [T_SLASH] = "/",
    [T_INTLIT] = "Int",
};

void scanfile(const char *file) {
    FILE *fp = fopen(file, "r");
    if (!fp) {
        fprintf(stderr, "File not found!\n");
        exit(1);
    }
    struct Scanner scanner;
    struct token t;
    scanner_init(&scanner, fp);
    while (scanner_next(&scanner, &t)) {
        printf("Token { type: %s", tokstr[t.type]);
        if (t.type == T_INTLIT) {
            printf(", value: %d }\n", t.value);
        } else {
            puts(" }");
        }
    }
    fclose(fp);
}

int main(int argc, char const *argv[]) {
#ifdef DEBUG
    scanfile("../input/01");
#else
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [file]\n", *argv);
        exit(1);
    }
    scanfile(argv[1]);
#endif
    return 0;
}
