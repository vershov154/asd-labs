def lower_bound(arr, x):
    l = -1
    r = len(arr)
    while r - l > 1:
        m = (l + r) // 2
        if arr[m] >= x:
            r = m
        else:
            l = m
    return r

def upper_bound(arr, x):
    l = -1
    r = len(arr)
    while r - l > 1:
        m = (l + r) // 2
        if arr[m] > x:
            r = m
        else:
            l = m
    return r

n = int(input())
arr1 = [int(x) for x in input().split()]
arr1.sort()

m_count = int(input())
arr2 = [int(x) for x in input().split()]

results = []
for query in arr2:
    first_pos = lower_bound(arr1, query)
    last_pos = upper_bound(arr1, query)
    
    count = last_pos - first_pos
    results.append(str(count))

print(" ".join(results))