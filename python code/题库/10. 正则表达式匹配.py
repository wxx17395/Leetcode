class Solution:
    # dfs + 字典
    def isMatch(self, s: str, p: str) -> bool:
        memo = dict()

        def dfs(i,j):
            if (i,j) in memo:
                return memo[(i,j)]
            if j == len(p):
                return i == len(s)

            firstMatch = i < len(s) and p[j] in {s[i], '.'}

            if j <= len(p) - 2 and p[j + 1] == '*':
                ans = dfs(i, j + 2) or firstMatch and dfs(i + 1, j)
            else:
                ans = firstMatch and dfs(i + 1, j + 1)

            memo[(i, j)] = ans
            return ans

        return dfs(0, 0)

    # 动态规划
    def isMatch_2(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)

        def matchs(i: int, j: int) -> bool:
            if i == 0:
                return False
            if p[i - 1] == '.':
                return True
            return s[i - 1] == p[j - 1]

        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = True
        for i in range(m + 1):
            for j in  range(1, n + 1):
                if p[j - 1] == '*':
                    dp[i][j] |= dp[i][j - 2]
                    if matchs(i, j - 1):
                        dp[i][j] |= dp[i - 1][j]
                else:
                    if matchs(i, j):
                        dp[i][j] |= dp[i - 1][j - 1]
        return dp[m][n]

if __name__ == '__main__':
    print(Solution().isMatch_2('aab','c*a*b'))


