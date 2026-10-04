def good(x, arr, k):    
    if x == 0:
        return True
    cnt = 0
    for length in arr:
        cnt += length // x
    return cnt >= k


n, k = map(int, input().split())

arr = []
for _ in range(n):
    arr.append(int(input()))

l = 0
r = 10**7 + 1
while r - l > 1:
    m = (l + r) // 2
    if good(m, arr, k):
        l = m 
    else:
        r = m 

print(l)
