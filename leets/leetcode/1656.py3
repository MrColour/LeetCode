class OrderedStream:
    total = 0
    curr = 0
    arr = []

    def __init__(self, n: int):
        self.total = n
        self.arr = [None] * n
        print(len(self.arr))

    def insert(self, idKey: int, value: str) -> List[str]:
        self.arr[idKey - 1] = value

        res = []
        for i in range(self.curr, self.total):
            if (self.arr[i] is None):
                break
            res += [self.arr[i]]

        self.curr = i
        return (res)
        


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)