def is_less_or_equal(left, right, x, n):
    a = b = 0
    if left >= x:
        a = left 
    else:
        a = left + n

    if right >= x:
        b = right
    else:
        b = right + n
    
    return a <= b


def merge_sort(arr, x, n):
    if len(arr) <= 1:
        return arr, 0
    mid = len(arr) // 2
    left, inv_left = merge_sort(arr[:mid], x, n)
    right, inv_right = merge_sort(arr[mid:], x, n)
    merged, inv_merge = merge(left, right, x, n)
    return merged, inv_left + inv_right + inv_merge


def merge(left, right, x, n):
    res = []
    i, j = 0, 0
    inv = 0
    while i < len(left) and j < len(right):
        if is_less_or_equal(left[i], right[j], x, n):
            res.append(left[i])
            i += 1
        else:
            res.append(right[j])
            inv += len(left) - i
            j += 1
    res += left[i:] + right[j:]
    return res, inv



n = int(input())
arr = list(map(int, input().split()))[:n]

min_transpositions = 10000000

for x in range(1, n + 1):
    merged, transpositions = merge_sort(arr, x, n)
    
    if transpositions < min_transpositions:
        min_transpositions = transpositions
            
print(min_transpositions)


