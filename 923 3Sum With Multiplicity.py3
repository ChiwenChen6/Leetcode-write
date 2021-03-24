class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        mod = 10**9 + 7
        c = Counter(arr)
        arr = sorted(c.keys())
        ans = 0
        for k in range(len(arr)-1, -1, -1):
            if arr[k] * 3 < target:
                break
            for j in range(k, -1, -1):
                if arr[j] * 2 < target - arr[k]:
                    break
                if (arri := target - arr[k] - arr[j]) >= 0 and arri in c and arri <= arr[j] <= arr[k]:
                    cc = Counter((arri, arr[j], arr[k]))
                    ans += reduce(operator.mul, (math.comb(c[n], v) for n, v in cc.items())) % mod
        return ans % mod

##Runtime: 116 ms, faster than 39.10% of Python3 online submissions for 3Sum With Multiplicity.
##Memory Usage: 14.5 MB, less than 21.05% of Python3 online submissions for 3Sum With Multiplicity.
