class Solution:
    def trap(self, height: List[int]) -> int:

        res=0
        left = [0]*len(height)
        right = [0]*len(height)

        left[0] = height[0]
        for i in range(0,len(height)):
            left[i]=max(left[i-1],height[i])
        
        right[len(height)-1] = height[len(height)-1]
        for i in range(len(height)-2,0,-1):
            right[i]=max(right[i+1],height[i])

        for i in range(1,len(height)-1):
            temp = min(left[i-1],right[i+1])
            if temp>height[i]:
                res+= (temp-height[i])
        
        return res
