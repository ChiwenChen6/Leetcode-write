class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.numbers = nums
        
    def add(self, val: int) -> int:
        self.numbers.append(val)
        self.numbers.sort()
        return self.numbers[-self.k]
    
# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
