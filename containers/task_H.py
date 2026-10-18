from collections import deque

n = int(input())

left = deque()
right = deque()

answers = []

for _ in range(n):
    line = input().split()
    command = line[0]

    if command == '+':
        goblin = line[1]
        right.append(goblin)
        
    elif command == '*':
        goblin = line[1]
        left.append(goblin)
        
    elif command == '-':
        answers.append(left.popleft())

    if len(left) < len(right):
        left.append(right.popleft())
    elif len(left) > len(right) + 1:
        right.appendleft(left.pop())

if answers:
    print('\n'.join(answers))