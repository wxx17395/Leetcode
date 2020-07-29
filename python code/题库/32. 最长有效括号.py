class Solution:
    # 利用栈
    def longestValidParentheses(self, s: str) -> int:
        stack = []
        stack.append(-1)
        length = len(s)
        maxConut = 0
        for i in range(length):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if len(stack) == 0:
                    stack.append(i)
                else:
                    maxConut = max(maxConut, i - stack[-1])
        return maxConut

    # 不使用额外空间，仅从左至右和从右至左各遍历一遍
    def longestValidParentheses1(self, s: str) -> int:
        left, right = 0, 0
        length = len(s)
        maxCount = 0
        for i in range(length):
            if s[i] == '(':
                left += 1
            else:
                right += 1
            if left == right:
                maxCount = max(maxCount, 2 * left)
            elif right > left:
                left, right = 0, 0
        left, right = 0, 0
        for i in range(length - 1, -1, -1):
            if s[i] == '(':
                left += 1
            else:
                right += 1
            if left == right:
                maxCount = max(maxCount, 2 * left)
            elif left > right:
                left, right = 0, 0
        return maxCount

    # 动态规划
    def longestValidParentheses2(self, s: str) -> int:
        length = len(s)
        dp = [0] * length
        maxCount = 0
        for i in range(1, length, 1):
            if s[i] == ')':
                if s[i - 1] == '(':
                    dp[i] = dp[i - 2] + 2 if i >= 2 else 2
                elif (i - dp[i - 1] > 0) and s[i - dp[i - 1] - 1] == '(':
                    dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2 if (i - dp[i - 1]) >= 2 else dp[i - 1] + 2
                maxCount = max(maxCount, dp[i])
        return maxCount

if __name__ == '__main__':
    print(Solution().longestValidParentheses2("(()"))

