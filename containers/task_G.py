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

tupik = Stack()
n = int(input())
vag = list(map(int, input().split()))[:n]

r = 1
while len(vag) > 0:
    if tupik.back() == r:
        tupik.pop()
        r += 1
    else:
        tupik.push(vag.pop(0))

while tupik.back() == r:
    tupik.pop()
    r += 1

if tupik.size() == 0:
    print("YES")
else:
    print("NO")