"""
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

from collections import defaultdict

class Solution:
    # hashmap
    def longestConsecutive(self, nums: list) -> int:
        hashmap = defaultdict(lambda :0)
        maxlen = 0
        for num in nums:
            if num not in hashmap or hashmap[num] == 0:
                prelen = hashmap[num - 1]
                nextlen = hashmap[num + 1]
                curlen = prelen + 1 + nextlen
                hashmap[num] = curlen
                maxlen = max(curlen, maxlen)
                hashmap[num - prelen] = curlen
                hashmap[num + nextlen] = curlen
        return maxlen

if __name__ == '__main__':
    print(Solution().longestConsecutive([100, 4, 200, 1, 3, 2]))