class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        res = []
        for i,j in enumerate(s):
            if j =='(':
                res.append([i,j])
            elif j ==')':
                if res==[] or res[-1][1] != '(':
                    res.append([i,j])
                else:
                    res.pop()
        s = list(s)
        for k,l in enumerate(res):
            s.pop(l[0]-k)
        return ''.join(s)
