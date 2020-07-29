"""
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
 

提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。

说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/product-of-array-except-self
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:
    # 正向遍历和反向遍历一边数组，L[i]和R[i]份分别表示i位置左侧数乘积和右侧数乘积
    # 但是该方法空间复杂度为O(n)
    def productExceptSelf_1(self, nums: list) -> list:
        n = len(nums)
        L, R = [1] * n, [1] * n
        res = list()
        cur = 1
        for i in range(1, n):
            L[i] = L[i - 1] * nums[i - 1]
        cur = 1
        for i in range(n-2, -1, -1):
            R[i] = R[i + 1] * nums[i + 1]
        for i in range(n):
            res.append(L[i] * R[i])
        return res

    # 上述方法的优化，仅使用一个res数组，先后代替L与R
    # 该方法空间复杂度为O(1)
    def productExceptSelf(self, nums: list) -> list:
        n = len(nums)
        res = [1] * n
        cur = 1
        for i in range(1, n):
            res[i] = res[i - 1] * nums[i - 1]
        cur = 1
        for i in range(n-2, -1, -1):
            cur = cur * nums[i + 1]
            res[i] = res[i] * cur
        return res

if __name__ == '__main__':
    print(Solution().productExceptSelf([1,2,3,4]))

