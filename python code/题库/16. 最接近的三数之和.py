class Solution:
    def threeSumClosest(self, nums, target: int) -> int:
        length = len(nums)
        nums.sort()
        minDif = float('inf')
        for k in range(length - 2):
            if k > 0 and nums[k] == nums[k-1]: continue
            i = k + 1
            j = length - 1
            while i < j:
                s = nums[k] + nums[i] + nums[j]
                curDif = s - target
                if curDif > 0:
                    j -= 1
                    while i < j and nums[j] == nums[j + 1]: j -= 1
                elif curDif < 0:
                    i += 1
                    while i < j and nums[i] == nums[i - 1]: i += 1
                else:
                    return s
                minDif = s if abs(curDif) < abs(minDif - target) else minDif
        return minDif