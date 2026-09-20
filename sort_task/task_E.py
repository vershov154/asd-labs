def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    i = len(arr) // 2
    left = merge_sort(arr[:i])
    right = merge_sort(arr[i:])
    return merge(left, right)

def merge(left, right):
    res = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            res.append(left[i])
            i += 1
        else:
            res.append(right[j])
            j += 1
    res += left[i:] + right[j:]
    return res


n = int(input())
arr = list(map(int, input().split()))[:n]
sorted_arr = merge_sort(arr)
print(*sorted_arr)