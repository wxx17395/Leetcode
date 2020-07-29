"""
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：2
示例 2：

输入：n = 7
输出：21
提示：

0 <= n <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution:
    # 递归，n=36时超时
    def numWays_1(self, n: int) -> int:
        self.count = 0
        def recursion(i):
            if i == n:
                self.count += 1
                return
            if i > n:
                return
            recursion(i+1)
            recursion(i+2)
        recursion(0)
        return self.count % 1000000007

    # 动态规划,dp(i)=max(dp(i-1)+1,dp(i-2)+2)
    def numWays_2(self, n: int) -> int:
        dp = []
        dp.append(1)
        dp.append(1)
        for i in range(2,n + 1):
            dp.append(dp[i - 1] + dp[i - 2])
        return dp[n] % 1000000007

    # 动态规划 + 优化,空间复杂度降为O(1)
    def numWays(self, n: int) -> int:
        a, b = 1, 1
        for i in range(n):
            a, b = b, a + b
        return a % 1000000007

if __name__ == '__main__':
    print(Solution().numWays(7))