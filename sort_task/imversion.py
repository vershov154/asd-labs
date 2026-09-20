def merge_sort(arr):
    if len(arr) <= 1:
        return arr, 0
    i = len(arr) // 2
    left, inv_left = merge_sort(arr[:i])
    right, inv_right = merge_sort(arr[i:])
    merged, inv_merge =  merge(left, right)
    return merged, inv_left + inv_right + inv_merge

def merge(left, right):
    res = []
    i, j = 0, 0
    inv = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]: # if left[i] <= right[j]: для полуинверсий
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
sorted_arr, inversions = merge_sort(arr)
print(inversions)

