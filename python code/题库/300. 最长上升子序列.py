class Solution:
    # 动态规划
    def lengthOfLIS(self, nums: list) -> int:
        if not nums:
            return 0
        dp = []
        for i in range(len(nums)):
            dp.append(1)
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)



if __name__ == '__main__':
    print(Solution().lengthOfLIS([10,11,2,5,3,4]))