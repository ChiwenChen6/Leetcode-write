class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        if not temperatures:
            return []
        n = len(temperatures)
        res = [0]*n
        stk = [(temperatures[0], 0)]
        for i in range(1, len(temperatures)):
            while stk and stk[-1][0] < temperatures[i]:
                val, idx = stk.pop()
                res[idx] = i-idx
            stk += (temperatures[i], i),
        return res
