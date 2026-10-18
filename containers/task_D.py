class Queue:
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
        return self.items.pop(0)

    def front(self):
        if self.is_empty():
            return "error"
        return self.items[0]   

    def size(self):
        return len(self.items)

    def clear(self):
        self.items = []
        return "ok"

queue = Queue()

while True:
    r = input().split()
    command = r[0]

    if command == "push":
        print(queue.push(int(r[1])))

    elif command == "pop":
        print(queue.pop())

    # Изменено с "back" на "front"
    elif command == "front":
        print(queue.front())

    elif command == "size":
        print(queue.size())
        
    elif command == "clear":
        print(queue.clear())

    elif command == "exit":
        print("bye")
        break