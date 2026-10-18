import sys

data = list(map(int, sys.stdin.read().split()))
if data:
    n = data[0]
    h = data[1:n+1]

    left = [0] * n
    right = [n - 1] * n

    stack = []

    for i in range(n):
        while stack and h[stack[-1]] >= h[i]:
            stack.pop()
        left[i] = stack[-1] + 1 if stack else 0
        stack.append(i)

    stack = []

    for i in range(n - 1, -1, -1):
        while stack and h[stack[-1]] >= h[i]:
            stack.pop()
        right[i] = stack[-1] - 1 if stack else n - 1
        stack.append(i)

    max_area = 0
    for i in range(n):
        width = right[i] - left[i] + 1
        current_area = h[i] * width
        if current_area > max_area:
            max_area = current_area

    print(max_area)
