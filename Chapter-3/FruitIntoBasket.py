import collections 
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:

        tempDict = collections.defaultdict(int)
        l = 0
        total = 0
        res = 0 
        farmLen = len(fruits)
        tempSet = set(fruits)

        if len(tempSet) < 3:
            return farmLen

        for r in range(len(fruits)):
            tempDict[fruits[r]]+=1
            total += 1 

            while len(tempDict) > 2:
                f = fruits[l]
                tempDict[f]-=1
                total -=1
                l+=1
                if not tempDict[f]:
                    tempDict.pop(f)
            res = max(res, total)
        return res 
