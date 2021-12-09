class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        stack = [start]
        while stack:
            i = stack.pop()
            if arr[i] == -1: 
                continue
            if arr[i] == 0: 
                return True
            li = i - arr[i]
            ri = i + arr[i]
            arr[i] = -1
            if 0 <= li and arr[li] != -1:
                stack.append(li)
            if ri < len(arr) and arr[ri] != -1:
                stack.append(ri)
        return False        
