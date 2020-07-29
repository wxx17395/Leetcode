
class Solution:
    # 贪心算法 + DFS
    def coinChange(self, coins: list, amount: int) -> int:
        def coinChange2(coins, amount, c_index, count, ans):
            if amount == 0:
                return min(ans, count)
            if c_index == len(coins):
                return ans
            k = amount // coins[c_index]
            while k >= 0 and k + count < ans:
                ans = coinChange2(coins, amount - k * coins[c_index], c_index + 1, count + k, ans)
                k -= 1
            return ans
        if amount == 0:
            return 0
        coins.sort(reverse=True)
        ans = coinChange2(coins, amount, 0, 0, float("inf"))
        return ans if ans != float("inf") else -1

    # 动态规划
    def coinChange(self, coins: list, amount: int) -> int:
        if not coins:
            return -1
        dp = [ amount + 1 for i in range(amount + 1) ]
        dp[0] = 0
        for i in range(amount + 1):
            for j in coins:
                if i - j < 0:
                    continue
                dp[i] = min(dp[i], 1 + dp[i - j])
        return dp[amount] if dp[amount] != amount + 1 else -1

if __name__ == '__main__':
    print(Solution().coinChange([186,419,83,408],6249))