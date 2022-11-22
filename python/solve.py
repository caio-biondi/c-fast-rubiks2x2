import ctypes
def solve():
    f = ctypes.CDLL('/Users/apple/Desktop/c-fast-rubiks2x2/C/librubiks.so').subgroup_generated

    py_state = (10, 11, 12, 4, 5, 6, 16, 17, 18, 21, 19, 20, 1, 2, 3, 14, 15, 13, 7, 8, 9)
    # py_state = (1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21)

    state = (ctypes.c_int * 21)()

    for i in range(0,21):
        state[i] = py_state[i]

    f.restype = ctypes.POINTER(ctypes.c_int * 14)

    res = [i for i in f(state).contents]
    res[:] = [x for x in res if x != -1]
    return res