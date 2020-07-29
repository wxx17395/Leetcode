class Solution:
    def fourSum(self, nums, target: int):
        length = len(nums)
        nums.sort()
        result = []
        for l in range(length - 3):
            if nums[l] + nums[l + 1] + nums[l + 2] + nums[l + 3] > target: break
            if l > 0 and nums[l] == nums[l - 1]: continue
            curTarget = target - nums[l]
            for r in range(l + 1, length - 2):
                if nums[r] + nums[r + 1] + nums[r + 2] > curTarget: break
                if r > l + 1 and nums[r] == nums[r - 1]: continue
                i = r + 1
                j = length - 1
                if nums[j] + nums[j - 1] + nums[j - 2] < curTarget: continue
                while i < j:
                    sum = nums[r] + nums[i] + nums[j]
                    if sum < curTarget:
                        i += 1
                        while i < j and nums[i] == nums[i - 1]: i += 1
                    elif sum > curTarget:
                        j -= 1
                        while i < j and nums[j] == nums[j + 1]: j -= 1
                    else:
                        result.append([nums[l], nums[r], nums[i], nums[j]])
                        i += 1
                        j -= 1
                        while i < j and nums[i] == nums[i - 1]: i += 1
                        while i < j and nums[j] == nums[j + 1]: j -= 1
        return result

if __name__ == '__main__':
    print(Solution().fourSum([-1,-5,-5,-3,2,5,0,4], -7))