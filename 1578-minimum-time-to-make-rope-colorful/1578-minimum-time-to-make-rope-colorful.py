class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        
        res,max_num = 0,0
        for i in range(len(colors)):
            if(i>0 and (colors[i] is not colors[i-1])):
                max_num = 0
            res += min (max_num,neededTime[i])
            max_num = max(max_num,neededTime[i])
        return res
            