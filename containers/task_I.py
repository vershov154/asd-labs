data = list(map(int, input().split()))
n = data[0]
balls = data[1:]

stack = []
destroyed = 0

for color in balls:
    while stack and stack[-1][0] != color and stack[-1][1] >= 3:
        destroyed += stack.pop()[1]
        
    if stack and stack[-1][0] == color:
        stack[-1][1] += 1
    else:
        stack.append([color, 1])

if stack and stack[-1][1] >= 3:
    destroyed += stack.pop()[1]

print(destroyed)
