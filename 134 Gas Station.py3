class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(cost) > sum(gas): 
            return -1
        index = tank = 0
        for i in range(len(gas)):
            tank += gas[i] - cost[i]
            if tank < 0: index, tank = i+1, 0
        return index
