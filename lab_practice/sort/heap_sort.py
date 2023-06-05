import math
class Heap():
    def __init__(self,arr):
        self.arr = arr + [0] 
        self.heap_size = len(self.arr)
        self.build_max_heap()
        self.is_heap = True


    def parent(self,i):
        return math.floor(i)
    def left(self,i):
        return i * 2
    def right(self,i):
        return i * 2 + 1

    def build_max_heap(self):
        for i in range(math.floor((len(self.arr)-1)//2),1,-1):
            self.heapify(i)

    def heapify(self,i):
        l = self.left(i)
        r = self.right(i)
        largest = 0
        if (l < self.heap_size) and (self.arr[l] > self.arr[i]):
            largest = l
        else:
            largest = i

        if (r < self.heap_size) and (self.arr[r] > self.arr[largest]):
            largest = r
        
        if largest != i:
            self.arr[i],self.arr[largest] = self.arr[largest],self.arr[i]
            self.heapify(largest)

    def heapsort(self):
        self.is_heap = False
        self.build_max_heap()
        for i in range(len(self.arr)-1,2,-1):
            self.arr[1],self.arr[i] = self.arr[i], self.arr[1]
            self.heap_size -= 1;
            self.heapify(1)

c = [6,7,2,1,2]
d = Heap(c)
d.heapsort()

print(d.arr)





        

