class RandomizedSet:
        

    def __init__(self):
        self._nums=[]
        self._positions={}

    def insert(self, val: int) -> bool:
        if val in self._positions:
            return False
        self._nums.append(val)
        self._positions[val]=len(self._nums)-1
        return True

    def remove(self, val: int) -> bool:
        if not val in self._positions:
            return False
        pos=self._positions[val]
        last_ele= self._nums[-1]
        self._nums[pos] = last_ele
        self._positions[last_ele] = pos
        self._nums.pop()
        self._positions.pop(val)
        return True

    def getRandom(self) -> int:
        return self._nums[random.randint(0,len(self._nums)-1)]

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()


Runtime: 547 ms, faster than 47.46% of Python3 online submissions for Insert Delete GetRandom O(1).
Memory Usage: 61.9 MB, less than 26.09% of Python3 online submissions for Insert Delete GetRandom O(1).
