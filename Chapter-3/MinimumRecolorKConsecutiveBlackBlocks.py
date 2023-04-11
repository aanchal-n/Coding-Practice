class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        res = 0
        temp = 0

        if k == len(blocks):
            return blocks.count('W')

        for i in range(0, len(blocks)-k+1):
            curStr = blocks[i:i+k]
            temp = curStr.count('W')

            if i == 0:
                res = temp 
            else:
                res = min(res, temp)
        
        return res
