class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        min_diff = sys.maxsize
        result = []
        for i, val in enumerate(arr[0:len(arr) - 1]):
            if arr[i+1]-val < min_diff:
                min_diff = arr[i+1]-val
                result = [[val, arr[i+1]]]
            elif arr[i+1]-val == min_diff:
                result.append([val, arr[i + 1]])
        return result
