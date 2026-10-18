class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)
        return "ok"

    def pop(self):
        if self.is_empty():
            return "error"
        return self.items.pop()

    def back(self):
        if self.is_empty():
            return "error"
        return self.items[-1]   

    def size(self):
        return len(self.items)

    def clear(self):
        self.items = []
        return "ok"

stack = Stack()

while True:
    r = input().split()
    command = r[0]

    if command == "push":
        print(stack.push(int(r[1])))

    elif command == "pop":
        print(stack.pop())

    elif command == "back":
        print(stack.back())

    elif command == "size":
        print(stack.size())
        
    elif command == "clear":
        print(stack.clear())

    elif command == "exit":
        print("bye")
        break