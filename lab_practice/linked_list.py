class Node:
    def __init__(self,value,previous=None):
        self.value = value
        self.previous = previous 




class LinkedList:
    def __init__(self):
        self.head = None 
        self.current = None

    def add(self, value):
        if self.head is None:
            self.head = Node(value)
            self.current = self.head
        else:
            node = Node(value,self.current)
            self.current = node
    
    def __repr__(self):
        point = self.current
        while point is not None:
            print(point.value)
            point = self.current.previous









