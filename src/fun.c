#include "../include/fun.h"
#include <stdio.h>
#include <stdlib.h>

void reverse(int arr[], int n)
{
    for (int low = 0, high = n - 1; low < high; low++, high--)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
}

int indexof(int arr[PERM_LEN]) {
    switch(arr[0]) {
        case 4:
            return 0;
        case 10:
            return 1;
        case 17:
            return 2;
        case 5:
            return 3;
        case 12:
            return 4;
        case 18:
            return 5;
    }
    return -1;
}

int* mul(int perm1[PERM_LEN], int perm2[PERM_LEN]) {
    int* ret = NULL;
    ret = (int *) malloc(PERM_SIZE);
    if (!ret) {
        printf("Could not allocate memory!");
        exit(-1);
    }
    int i = 0;
    while(i < PERM_LEN) {
        ret[i] = perm1[perm2[i]-1];
        ++i;
    }
    return ret;
}