def good(days, a, k, b, m, x):
    dmitry_days = days - (days // k)
    fedor_days = days - (days // m)
    
    total_trees = dmitry_days * a + fedor_days * b
    
    return total_trees >= x


a, k, b, m, x = map(int, input().split())

l = 0
r = 10**18 

while r - l > 1:
    mid = (l + r) // 2
    if good(mid, a, k, b, m, x):
        r = mid
    else:
        l = mid
print(r)
