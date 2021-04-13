class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        arr = [0] *n
        arr[0] = 1
        c = k 
        for i in range(1,k+1):
            if i % 2 ==1:
                arr[i] = arr[i-1] +k
                k -= 1
            else:
                arr[i] = arr[i-1] -k
                k -= 1
        for i in range(c+1, n):
            arr[i] = i+1
        return arr
        
# Status: Accepted
# Runtime: 52 ms
# Memory Usage: 15.1 MB
