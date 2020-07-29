"""
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3
 

限制：

2 <= n <= 100000



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from collections import defaultdict
class Solution:
    def mainFunc(self, nums: list):
        return self.findRepeatNumber(nums)

    # hash表，时间O(n)，空间O(n)
    def findRepeatNumber_1(self, nums: list) -> int:
        hashmap = defaultdict(lambda: 0)
        for i in range(len(nums)):
            if nums[i] not in hashmap:
                hashmap[nums[i]] = 1
            else:
                return nums[i]

    # 数组交换，时间O(n)，空间O(1)，但是需要修改原数组
    def findRepeatNumber(self, nums: list) -> int:
        for i in range(len(nums)):
            # nums[i] == i时，不需要交换
            if nums[i] != i:
                if nums[i] == nums[nums[i]]:
                    return nums[i]
                else:
                    temp = nums[nums[i]]
                    nums[nums[i]] = nums[i]
                    nums[i] = temp

if __name__ == '__main__':
    print(Solution().mainFunc([0,1,2,3]))