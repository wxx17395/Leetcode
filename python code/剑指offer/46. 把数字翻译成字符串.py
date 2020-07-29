"""
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"

提示：

0 <= num < 231

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:
    # dfs
    def translateNum_1(self, num: int) -> int:
        s = str(num)
        n = len(s)
        if n == 1:
            return 1
        self.cnt = 0

        def dfs(i, flag):
            if i >= n - 1:
                self.cnt += 1
                return
            dfs(i + flag, 1)
            if i + flag < n - 1 and s[i + flag] != '0' and int(s[i + flag : i + flag + 2]) < 26:
                dfs(i + flag, 2)

        dfs(0, 1)
        if s[0] != '0' and int(s[0 : 2]) < 26:
            dfs(0, 2)
        return self.cnt

    # 动归
    def translateNum(self, num: int) -> int:
        s= str(num)
        p, q, r = 0, 0, 1
        for i in range(len(s)):
            p = q
            q = r
            r = 0
            r += q
            if i == 0:
                continue
            pre = s[i - 1: i + 1]
            if '10' <= pre <= '25':
                r += p
        return r


if __name__ == '__main__':
    print(Solution().translateNum(758212932))

