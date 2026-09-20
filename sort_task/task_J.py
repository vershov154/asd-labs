from functools import cmp_to_key
from sys import stdin

def compare(x, y):
    if x + y < y + x:
        return 1
    elif x + y > y + x:
        return -1
    else:
        return 0 

lines = stdin.read().split()

ls = sorted(lines, key=cmp_to_key(compare))
print(''.join(ls))
