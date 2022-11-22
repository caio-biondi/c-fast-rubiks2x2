#ifndef STUFF_H
#define STUFF_H

#define U {4,5,6,7,8,9,10,11,12,1,2,3,13,14,15,16,17,18,19,20,21}
#define UP {10,11,12,1,2,3,4,5,6,7,8,9,13,14,15,16,17,18,19,20,21}
#define R {17,18,16,3,1,2,7,8,9,10,11,12,13,14,15,19,20,21,4,5,6}
#define RP {5,6,4,19,20,21,7,8,9,10,11,12,13,14,15,3,1,2,16,17,18}
#define F {12,10,11,4,5,6,7,8,9,13,14,15,16,17,18,2,3,1,19,20,21}
#define FP {18,16,17,4,5,6,7,8,9,2,3,1,10,11,12,13,14,15,19,20,21}

#define PERM_LEN 21
#define VEC_LEN 14

#define VEC_SIZE 14*sizeof(int)
#define PERM_SIZE 21*sizeof(int)

#ifndef DELETE
#define DELETE \
        delete_all(&g_elts);\
        delete_all(&elts_old);\
        delete_all(&elts_new);
#endif

#endif