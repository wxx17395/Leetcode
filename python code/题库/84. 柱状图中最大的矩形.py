"""
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

示例:

输入: [2,1,5,6,2,3]
输出: 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:
    def mainFunc(self, heights: list) -> int:
        return self.largestRectangleArea(heights)

    # 单调栈
    def largestRectangleArea_1(self, heights: list) -> int:
        n = len(heights)
        if n == 0:
            return 0
        left, right = [0] * n, [0] * n

        monotonous_stack = list()
        for i in range(n):
            while monotonous_stack and heights[monotonous_stack[-1]] >= heights[i]:
                monotonous_stack.pop()
            left[i] = monotonous_stack[-1] if monotonous_stack else -1
            monotonous_stack.append(i)

        monotonous_stack = list()
        for i in range(n - 1, -1, -1):
            while monotonous_stack and heights[monotonous_stack[-1]] >= heights[i]:
                monotonous_stack.pop()
            right[i] = monotonous_stack[-1] if monotonous_stack else n
            monotonous_stack.append(i)

        ans = max((right[i] - left[i] - 1) * heights[i] for i in range(n))
        return ans

    # 单调栈+优化
    # 只用遍历一遍
    def largestRectangleArea(self, heights: list) -> int:
        n = len(heights)
        if n == 0:
            return 0
        left, right = [0] * n, [n] * n

        monotonous_stack = list()
        for i in range(n):
            while monotonous_stack and heights[monotonous_stack[-1]] >= heights[i]:
                right[monotonous_stack[-1]] = i
                monotonous_stack.pop()
            left[i] = monotonous_stack[-1] if monotonous_stack else -1
            monotonous_stack.append(i)

        ans = max((right[i] - left[i] - 1) * heights[i] for i in range(n))
        return ans

if __name__ == '__main__':
    print(Solution().mainFunc([2,4]))