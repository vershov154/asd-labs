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

    def next_element(self, val):
        curr = self.root
        ans = -1
        while curr is not None:
            if curr.data == val:
                return val
            elif curr.data > val:
                ans = curr.data
                curr = curr.left
            else:
                curr = curr.right
        return ans


bst = BinarySearchTree()
n = int(input())
last_y = 0
prev_was_query = False
mod = 10**9

for _ in range(n):
    op, val_str = input().split()
    val = int(val_str)

    if op == "+":
        if prev_was_query:
            val = (val + last_y) % mod
        bst.insert(val)
        prev_was_query = False
    elif op == "?":
        last_y = bst.next_element(val)
        print(last_y)
        prev_was_query = True
