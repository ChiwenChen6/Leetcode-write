class Solution:
    def reorderedPowerOf2(self, N: int) -> bool:
        c1 = Counter(str(N))
        for i in range(30):
            n = int(math.pow(2, i))
            if Counter(str(n)) == c1: 
                return True
        return False
