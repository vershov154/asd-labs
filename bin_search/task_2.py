def bin_close(arr, x):
    l = -1
    r = len(arr)
    while r - l > 1:
        m = (l + r) // 2
        if arr[m] >= x:
            r = m
        else:
            l = m

    if r == len(arr):
        return arr[l]
    if l == -1:
        return arr[r]

    if abs(x - arr[l]) <= abs(x - arr[r]):
        return arr[l]
    else:
        return arr[r]
    
        

N, K = map(int, input().split())

arr1 = [int(x) for x in input().split()]
arr2= [int(x) for x in input().split()]

for elem in arr2:
        print(bin_close(arr1, elem))
