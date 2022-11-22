#include "../include/dict.h"
#include "../include/fun.h"
#include "../include/rubiks.h"

#include <stdio.h>
#include <string.h>

st *g_elts = NULL;
st *elts_new = NULL;
st *elts_old = NULL;

static inline void *MallocOrDie(size_t MemSize)
{
    void *AllocMem = malloc(MemSize);
    /* Some implementations return null on a 0 length alloc,
     * we may as well allow this as it increases compatibility
     * with very few side effects */
    if(!AllocMem && MemSize)
    {
        printf("Could not allocate memory!");
        exit(-1);
    }
    return AllocMem;
}

int* subgroup_generated(int perm[PERM_LEN]) {
    int gens[6][PERM_LEN] = {U,UP,R,RP,F,FP};
    int vec[VEC_LEN] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    int e[PERM_LEN] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};

    add_st(&g_elts, perm, vec, 0);
    add_st(&elts_new, perm, NULL, 0);

    int y = 0;
    while((unsigned int) HASH_COUNT(elts_new)) {
        delete_all(&elts_old);

        elts_old = elts_new;
        elts_new = NULL;

        st *x;
        for(x = elts_old; x != NULL; x = x->hh.next) {
            y = 0;
            while(y < 6) {
                int *p = mul(*(gens+y), x->perm);
                if(find_st(&g_elts, p) == NULL) {
                    st *g_elts_x = find_st(&g_elts, x->perm);

                    if(memcmp(e, p, sizeof(e)) == 0) {
                        int *res = NULL;

                        res = (int *) MallocOrDie(VEC_SIZE);
                        memcpy(res, g_elts_x->vec, VEC_SIZE);
                        res[g_elts_x->i] = indexof(gens[y]);

                        reverse(res, 14);
                        DELETE
                        free(p);
                        return res;
                    }
                    int new_i = 0;
                    int *new_vec = NULL;

                    new_vec = (int *) MallocOrDie(VEC_SIZE);
                    memcpy(new_vec, g_elts_x->vec, VEC_SIZE);
                    new_vec[g_elts_x->i] = indexof(gens[y]);
                    new_i = g_elts_x->i+1;

                    add_st(&g_elts, p, new_vec, new_i);
                    add_st(&elts_new, p, NULL, 0);
                }++y;
            }
        }
    }
    DELETE
    return NULL;
}

// void solve(int state[PERM_LEN]) {
//     int gens[6][PERM_LEN] = {U,UP,R,RP,F,FP};
//     const char moves[6][3] = {"U", "UP", "R", "RP", "F", "FP"};
//     int * x = subgroup_generated(state, gens);
//     int i = 0;
//     if (!x) {return;}
//     while(i < 14) {
//         int y = x[i];
//         if(y != -1) {
//             printf("%s ", moves[y]);
//         }
//         ++i;
//     }
//     free(x);
// }