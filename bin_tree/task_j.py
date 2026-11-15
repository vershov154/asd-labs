class Node:
    def __init__(self, data):
        self.data = data
        self.count = 1 
        self.left = None
        self.right = None


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, val):
        if self.root is None:
            self.root = Node(val)
            return

        curr = self.root
        while True:
            if val == curr.data:
                curr.count += 1
                return
            elif val < curr.data:
                if curr.left is None:
                    curr.left = Node(val)
                    return
                curr = curr.left
            else:
                if curr.right is None:
                    curr.right = Node(val)
                    return
                curr = curr.right

    def print_freq(self, node):
        if node is None:
            return
        self.print_freq(node.left)
        print(node.data, node.count)
        self.print_freq(node.right)


bst = BinarySearchTree()
numbers = map(int, input().split())

for x in numbers:
    if x == 0:
        break
    bst.insert(x)

bst.print_freq(bst.root)
