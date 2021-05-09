class Solution:
    def isPossible(self, target: List[int]) -> bool:
        heap = [-el for el in target]
        heapq.heapify(heap)
        
        sum_heap = sum(target)
        
        if len(target) ==1: return target[0] == 1
        
        while sum_heap > len(target): 
            curr = -1.*heapq.heappop(heap)
            sum_rest = sum_heap - curr
            if sum_rest > curr : return False
            if sum_rest ==1: return True
            prev = curr % sum_rest 
            if prev < 1: return False
            sum_heap = sum_rest + prev
            heapq.heappush(heap, -prev)
            
        return True
