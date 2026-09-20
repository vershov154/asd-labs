def merge_sort(arr):
    if len(arr) <= 1:
        return arr, 0
    mid = len(arr) // 2
    left, inv_left = merge_sort(arr[:mid])
    right, inv_right = merge_sort(arr[mid:])
    merged, inv_merge = merge(left, right)
    return merged, inv_left + inv_right + inv_merge

def merge(left, right):
    res = []
    i, j = 0, 0
    inv = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            res.append(left[i])
            i += 1
        else:
            res.append(right[j])
            inv += len(left) - i
            j += 1
    res += left[i:] + right[j:]
    return res, inv

n = int(input())
A = list(map(int, input().split()))[:n]
B = list(map(int, input().split()))[:n]

pos_in_A = [0] * (n + 1)
for id, value in enumerate(A):
    pos_in_A[value] = id

transformed_B = [pos_in_A[value] for value in B]

mer, ans = merge_sort(transformed_B)
print(ans)