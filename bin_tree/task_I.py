class Node:
    def __init__(self, data):
        self.data = data
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

    def height(self, node):
        if node is None:
            return 0
        return 1 + max(self.height(node.left), self.height(node.right))

    def is_balanced(self, node):
        if node is None:
            return True
        left_h = self.height(node.left)
        right_h = self.height(node.right)
        return (abs(left_h - right_h) <= 1 and
                self.is_balanced(node.left) and
                self.is_balanced(node.right))


bst = BinarySearchTree()
numbers = map(int, input().split())

for x in numbers:
    if x == 0:
        break
    bst.insert(x)

if bst.is_balanced(bst.root):
    print("YES")
else:
    print("NO")
