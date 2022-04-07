class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        
        while len(stones) > 1:
            first = max(stones)
            stones.pop(stones.index(first))
            second = max(stones)
            stones.pop(stones.index(second))
            
            if abs(first - second) > 0:
                stones.append(abs(first - second))
        if len(stones) == 0:
            return 0
        return stones[0]
