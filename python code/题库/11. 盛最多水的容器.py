class Solution:
    def maxArea(self, height) -> int:
        left, right = 0, len(height) - 1
        maxarea, currentarea= 0, 0
        while left < right:
            if height[left] >= height[right]:
                currentarea = ( right - left ) * height[right]
                right -= 1
            else:
                currentarea = ( right - left ) * height[left]
                left += 1
            if currentarea > maxarea:
                maxarea = currentarea
        return maxarea

if __name__ == '__main__':
    print(Solution().maxArea([1,8,6,2,5,4,8,8,7]))
