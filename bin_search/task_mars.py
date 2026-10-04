import sys

def good(d, n, a, b, w, h):
    new_w = w + 2 * d
    new_h = h + 2 * d
    
    count1 = (a // new_w) * (b // new_h)
    
    count2 = (a // new_h) * (b // new_w)
    
    return max(count1, count2) >= n

input_data = sys.stdin.read().split()

if input_data:
    n = int(input_data[0])
    a = int(input_data[1])
    b = int(input_data[2])
    w = int(input_data[3])
    h = int(input_data[4])

    l = 0
    r = max(a, b) + 1
    
    while r - l > 1:
        mid = (l + r) // 2
        if good(mid, n, a, b, w, h):
            l = mid 
        else:
            r = mid 
            
    print(l)
