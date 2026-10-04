def bin_search(arr, x):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == x:
            return True
        elif x > arr[mid]:
            left = mid + 1
        else:
            right = mid - 1
    return False

N, K = map(int, input().split())

arr1 = [int(x) for x in input().split()]
arr2= [int(x) for x in input().split()]

for elem in arr2:
        if bin_search(arr1, elem):
            print("YES")
        else:
            print("NO")