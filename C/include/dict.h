#ifndef DICT_H
#define DICT_H
#include "uthash.h"
#include "stuff.h"

typedef struct st {
    int *perm;
    int *vec;
    int i;
    UT_hash_handle hh;
}st;

void add_st(st **sts, int perm[PERM_LEN], int vec[VEC_LEN], int i);

struct st* find_st(st **sts, int perm[PERM_LEN]);

void delete_all(st **sts);

#endif