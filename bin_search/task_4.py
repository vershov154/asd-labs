def f(x, a, b, c, d):
    return a * x**3 + b * x**2 + c * x + d

a, b, c, d = map(float, input().split())

l = -2000
r = 2000

for _ in range(100):
    m = (r + l) / 2

    f_l = f(l, a, b, c, d)
    f_m = f(m, a, b, c, d)

    if (f_l > 0 and f_m > 0) or (f_l < 0 and f_m < 0):
        l = m
    else:
        r = m
print(f"{l:.11f}")