class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n,start,total_fuel,curr_fuel = len(gas),0,0,0
        for i in range (n):
            total_fuel += gas[i] - cost[i]
            curr_fuel += gas[i] - cost[i]
            if(curr_fuel<0):
                curr_fuel = 0
                start = i+1
        return -1 if (total_fuel<0) else start