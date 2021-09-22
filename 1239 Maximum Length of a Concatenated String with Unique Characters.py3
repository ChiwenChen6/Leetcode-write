class Solution:
    def maxLength(self, arr: List[str]) -> int:
        ans = [""]
        for x in arr: 
            for i in range(len(ans)):
                xx = x + ans[i]
                if len(xx) == len(set(xx)): 
                    ans.append(xx)
        return max(len(x) for x in ans)
