def f(x):
    return x**2 + x**0.5

c = float(input())
    
l = 0
r = 100000 # так как макс. C = 10^10, корень из него не превысит 10^5

# for _ in range(100):
#     m = (l + r) / 2
#     if f(m) < c:
#         l = m
#     else:
#         r = m

while True:
    m = (l + r) / 2
    if m <= l or m >= r:
        break
    if f(m) < c:
        l = m
    else:
        r = m

print(f"{l:.9f}")