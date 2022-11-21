#include "../include/dict.h"
#include <stdio.h>

void add_st(st **sts, int perm[PERM_LEN], int vec[VEC_LEN], int i) {
    st *s = NULL;
    s = (st *) malloc(sizeof*s);
    if(!s) {
        printf("Could not allocate memory!");
        exit(-1);
    }
    s->perm=perm;
    s->vec=vec;
    s->i = i;
    HASH_ADD_KEYPTR(hh, *sts, s->perm, PERM_SIZE, s);
}

st * find_st(st **sts, int perm[PERM_LEN]) {
    st *s;
    HASH_FIND(hh, *sts, perm, PERM_SIZE, s);
    return s;
}

void delete_all(st **sts) {
    st *current_state, *tmp;

    HASH_ITER(hh, *sts, current_state, tmp) {
        HASH_DEL(*sts, current_state);  /* delete; users advances to next */
    free(current_state);             /* optional- if you want to free  */
  }
}

