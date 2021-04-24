class CustomStack:

    def __init__(self, maxSize: int):
        self.max = maxSize
        self.stack = []

    def push(self, x: int) -> None:
        if (len(self.stack) == self.max):
            return
        self.stack.append(x)
        

    def pop(self) -> int:
        if (len(self.stack) == 0):
            return -1
        return (self.stack.pop())

    def increment(self, k: int, val: int) -> None:
        change = min(len(self.stack), k)

        for i in range(change):
            self.stack[i] += val
        


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()