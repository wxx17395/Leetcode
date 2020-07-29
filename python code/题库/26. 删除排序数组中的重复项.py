class Solution:
    # 双指针
    def removeDuplicates(self, nums):
        if not nums:
            return 0
        count = 0
        cur = 0
        while cur < len(nums):
            if nums[count] == nums[cur]:
                cur += 1
            else:
                count += 1
                nums[count] = nums[cur]
                cur += 1
        return count + 1

if __name__ == '__main__':
    print(Solution().removeDuplicates([1,1,2,2,3]))


