from collections import defaultdict
class Solution:
    # hash表
    def majorityElement_1(self, nums) -> int:
        frequency = defaultdict(lambda :0)
        for i in nums:
            if frequency[i]:
                frequency[i] += 1
            else:
                frequency[i] = 1
        for j in frequency:
            if frequency[j] > len(nums)/2 :
                return j

    # 排序后的中位数
    def majorityElement_2(self, nums) -> int:
        nums.sort()
        return nums[len(nums)//2]

    # 摩尔投票法
    def majorityElement(self, nums) -> int:
        count, candidate = 0, -1
        for i in nums:
            if count == 0:
                candidate = i
            count += 1 if i == candidate else -1
        return candidate

if __name__ == '__main__':
    print(Solution().majorityElement([3,2,2,2,3]))
