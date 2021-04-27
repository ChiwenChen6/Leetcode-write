class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        climb = [0] + [max(0, heights[i]-heights[i-1]) for i in range(1, len(heights))]
            
        i = 0
        j = len(climb) - 1
        count = 0
        while i + 1 < j:
            mid = i + (j-i)//2
            arr = sorted(climb[:mid+1],reverse=True)
            if len(arr) <= ladders or sum(arr[ladders:]) <= bricks:
                i = mid
            else:
                j = mid
                
		# we can reach j if j is reachable, otherwise we can reach i
        arr = sorted(climb[:j+1], reverse=True)
        if len(arr) <= ladders or sum(arr[ladders:]) <= bricks:
            return j
        else:
            return i
