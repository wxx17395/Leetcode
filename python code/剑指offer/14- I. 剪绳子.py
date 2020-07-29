"""
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
提示：

2 <= n <= 58
注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jian-sheng-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

from math import pow

class Solution:
    # 1.当n≤3时，按照规则应不切分，但由于题目要求必须剪成m>1段，因此必须剪出一段长度为1的绳子，即返回 n - 1。
    # 2.当n>3时，求n除以3的整数部分a和余数部分b（即n=3a+b），并分为以下三种情况：
    #   a) 当b=0时，直接返回3^a
    #   b) 当b=1时，要将一个1+3转为2+2，因为2*2>3*1
    #   c) 当b=2时，返回3^a*2
    def cuttingRope(self, n: int) -> int:
        if n <= 3:
            return n - 1
        a = n // 3
        b = n % 3
        if b == 0:
            return int(pow(3, a))
        if b == 1:
            return int(pow(3, a - 1) * 4)
        return int(pow(3, a) * 2)

    # 动归
    def cuttingRope_1(self, n: int) -> int:
        dp = [0 for _ in range(n + 1)]
        dp[2] = 1
        for i in range(3, n + 1):
            for j in range(i):
                dp[i] = max(dp[i], max((i - j) * j, j * dp[i - j]))
        return dp[n]

if __name__ == '__main__':
    print(Solution().cuttingRope_1(11))