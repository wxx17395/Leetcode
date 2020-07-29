class Solution:
    # 双指针
    def removeElement(self, nums, val: int) -> int:
        count = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[count] = nums[i]
                count += 1
        return count

if __name__ == '__main__':
    print(Solution().removeElement1([3,2,2,3,1],3))
