class Node():
    def __init__(self, val, left=None, right=None):
        self.value = val
        self.left = left
        self.right = right

    def __repr__(self):
        return f'({self.value})'


class Bst():
    def __init__(self):
        self.head = None

    def add(self, value):
        if self.head is None:
            self.head = Node(value)
        else:
            # do the traversal
            point = self.head
            left_flag = 0
            while (True):
                if point.value < value:
                    if (point.right == None):
                        point.right = Node(value)
                        break
                    point = point.right
                else:
                    if (point.left == None):
                        point.left = Node(value)
                        break
                    point = point.left

    def __repr__(self):
        data = []

        def traverse(point):
            data.append((point.value, point.left, point.right))
            if point.left is not None:
                traverse(point.left)
            elif point.right is not None:
                traverse(point.right)

        traverse(self.head)
        return str(data)


a = Bst()
a.add(3)
a.add(7)
a.add(8)

print(a)
