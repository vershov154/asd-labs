class MaxHeap:
    def __init__(self):
        self.heap = [0]
        self.size = 0

    def shiftUp(self, i):  # просеивание вверх
        while i // 2 > 0 and self.heap[i] > self.heap[i // 2]:
            self.heap[i], self.heap[i // 2] = self.heap[i // 2], self.heap[i]
            i = i // 2

    def insert(self, x):
        self.heap.append(x)
        self.size += 1
        self.shiftUp(self.size)

    def shiftDown(self, i):  # просеивание вниз
        while i * 2 <= self.size:
            j = self.indMaxChild(i)
            if self.heap[i] < self.heap[j]:
                self.heap[i], self.heap[j] = self.heap[j], self.heap[i]
            i = j

    def indMaxChild(self, i):
        if i * 2 + 1 > self.size:
            return i * 2
        if self.heap[i * 2] > self.heap[i * 2 + 1]:
            return i * 2
        return i * 2 + 1

    def delMax(self):
        if self.size == 0:
            return None
        removed = self.heap[1]
        self.heap[1] = self.heap[self.size]
        self.size = self.size - 1
        self.heap.pop()
        self.shiftDown(1)
        return removed

    def getMax(self):
        if self.size == 0:
            return None
        return self.heap[1]

ls = [100, 10, 20, 9, 8, 7, 6]


heap = MaxHeap()

for item in ls:
    heap.insert(item)
    print(f'+[{item:3d}]: Heap: {heap.heap[1:]}')

print('Maximum =', heap.getMax())

# сортировка по убыванию
while heap.size > 0:
    print(heap.delMax(), end=' ')
print()