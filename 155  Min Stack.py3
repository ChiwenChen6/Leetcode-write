class MinStack:

    def __init__(self):

        self.stack =[[]]
        

    def push(self, x: int) -> None:
        self.stack.append([x])
        

    def pop(self) -> None:
        k = self.stack.pop()
        return k[0]
        

    def top(self) -> int:
        return self.stack[-1][0]
        

    def getMin(self) -> int:
        out = 2**31
        for i in self.stack:
            if i and i[0] <out:
                out =i[0]
        return out


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()



# Runtime: 2732 ms, faster than 5.03% of Python3 online submissions for Min Stack.
# Memory Usage: 18.4 MB, less than 19.41% of Python3 online submissions for Min Stack.
