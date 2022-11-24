import ctypes
from functools import reduce

def solve_cube(str):
    f = ctypes.CDLL('/Users/apple/Desktop/c-fast-rubiks2x2/C/librubiks.so').subgroup_generated
    
    if len(str) != 21: return "Invalid State"
    if str == "oybogyowgobwwbrrbygry": return "Cube already solved! :)"
    
    # owgboyyogwbryrbwobryg
    
    color_dict = {"boy":{'o':1,'y':2,'b':3},
                "goy":{'o':4,'g':5,'y':6},
                "gow":{'o':7,'w':8,'g':9},
                "bow":{'o':10,'b':11,'w':12},
                "brw":{'w':13,'b':14,'r':15},
                "bry":{'r':16,'b':17,'y':18},
                "gry":{'g':19,'r':20,'y':21},
            }
    
    py_state = []
    
    try:
        for i in range(2,22,3):
            c = str[i-2:i+1]
            c_sort = sorted(c)
            key = ''
            for i in c_sort: key += i
            for i in c: py_state.append(color_dict[key][i])
    except:
        return "Invalid State"
        
    py_state = tuple(py_state)

    state = (ctypes.c_int * 21)()

    for i in range(0,21):
        state[i] = py_state[i]

    f.restype = ctypes.POINTER(ctypes.c_int * 14)

    res = [i for i in f(state).contents]
    res[:] = [x for x in res if x != -1]
    
    res_str = ""
    
    for i in res:
        res_str += ["U", "UP", "R", "RP", "F", "FP"][i] + " "
    return res_str