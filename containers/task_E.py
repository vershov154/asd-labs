class Deque():
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push_front(self, item):
        self.items.insert(0, item)
        return "ok"

    def push_back(self, item):
        self.items.append(item)
        return "ok"

    def pop_front(self):
        if self.is_empty():
            return "error"
        return self.items.pop(0)

    def pop_back(self):
        if self.is_empty():
            return "error"
        return self.items.pop()

    def front(self):
        if self.is_empty():
            return "error"
        return self.items[0]

    def back(self):
        if self.is_empty():
            return "error"
        return self.items[-1]

    def size(self):
        return len(self.items)

    def clear(self):
        self.items = []
        return "ok"



deque = Deque()

while True:
    line = input().split()
    if not line:
        continue
        
    command = line[0]

    if command == "push_front":
        print(deque.push_front(int(line[1])))
    elif command == "push_back":
        print(deque.push_back(int(line[1])))
    elif command == "pop_front":
        print(deque.pop_front())
    elif command == "pop_back":
        print(deque.pop_back())
    elif command == "front":
        print(deque.front())
    elif command == "back":
        print(deque.back())
    elif command == "size":
        print(deque.size())
    elif command == "clear":
        print(deque.clear())
    elif command == "exit":
        print("bye")
        break

 