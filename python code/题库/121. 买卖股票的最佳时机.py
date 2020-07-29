class Solution:
    # 双循环/暴力法
    def maxProfit_1(self, prices):
        max = 0
        left, right = 0, 0
        while left < len(prices):
            right = left + 1
            while right < len(prices):
                if prices[right] > prices[left]:
                    cur = prices[right] - prices[left]
                    if cur > max: max = cur
                right += 1
            left += 1
        return max

    # 单循环/滑动窗口
    def maxProfit_2(self, prices):
        minprice, maxprofit = float("inf"), 0
        for i in range(len(prices)):
            if prices[i] < minprice:
                minprice = prices[i]
            else:
                maxprofit = max(prices[i] - minprice, maxprofit)
        return maxprofit

    # 单调栈
    def maxProfit_3(self, prices):
        maxprofit = 0
        prices.append(-1)
        stack = []
        for i in range(len(prices)):
            if not stack:
                stack.append(prices[i])
            else:
                while stack and stack[-1] > prices[i]:
                    popprice = stack.pop()
                    if stack: maxprofit = max(maxprofit, popprice - stack[0])
                stack.append(prices[i])
        return maxprofit

    # 动态规划
    def maxProfit(self, prices):
        if len(prices) <= 1:
            return 0
        minprice, maxprofit = prices[0], 0
        for i in range(1, len(prices)):
            minprice = min(prices[i], minprice)
            maxprofit = max(maxprofit, prices[i] - minprice)
        return maxprofit


if __name__ == '__main__':
    print(Solution().maxProfit([3,2,4,0,3]))


