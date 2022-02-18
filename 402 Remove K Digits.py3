class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        res = list()
        numRemoved = 0 
        for tmp in num:
            while res and res[-1] > tmp and numRemoved < k:
                res.pop()
                numRemoved += 1
            res.append(tmp)
        
        while numRemoved < k:
            res.pop()
            numRemoved += 1
        
        while res and res[0] == '0': 
            res.pop(0)
        
        if len(res) == 0: 
            return '0'
			
        return ''.join(res)
