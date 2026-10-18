class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.is_empty():
            return False
        return self.items.pop()

    def back(self):
        if self.is_empty():
            return False
        return self.items[-1]   

    def size(self):
        return len(self.items)

    def clear(self):
        self.items = []


N = int(input())

for _ in range(N):
    nakop = Stack()
    
    data = list(map(float, input().split()))
    K = int(data[0])
    lenta = data[1:K+1]
    
    B = sorted(lenta)
    
    num = 0
    
    while len(lenta) > 0:
        if num < K and nakop.back() == B[num]:
            nakop.pop()
            num += 1
        else:
            nakop.push(lenta.pop(0))

    while num < K and nakop.back() == B[num]:
        nakop.pop()
        num += 1

    if nakop.size() == 0:
        print(1)
    else:
        print(0)
