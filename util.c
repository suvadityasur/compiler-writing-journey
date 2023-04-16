//
// Created by suvaditya on 4/15/23.
//

#include "util.h"

void *alloc(size_t size) {
    void *p = calloc(1, size);
    if (!p) {
        fprintf(stderr, "alloc(%zu) failed.\n", size);
        exit(1);
    }
    return p;
}
