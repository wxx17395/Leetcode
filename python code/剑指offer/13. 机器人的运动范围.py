"""
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

示例 1：

输入：m = 2, n = 3, k = 1
输出：3
示例 2：

输入：m = 3, n = 1, k = 0
输出：1
提示：

1 <= n,m <= 100
0 <= k <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:
    # 从(0，0)出发，只需要向(0,1)和(1,0)两个方向移动
    def movingCount(self, m: int, n: int, k: int) -> int:
        self.count = 0
        moved = [[0 for i in range(n)] for j in range(m)]

        def check(x, y):
            if x >= m or y >= n or moved[x][y] == 1:
                return False
            sum = 0
            while x != 0:
                sum += x % 10
                x = x // 10
            while y != 0:
                sum += y % 10
                y = y // 10
            return True if sum <= k else False

        def move(x, y):
            self.count += 1
            moved[x][y] = 1
            if check(x + 1, y):
                move(x + 1, y)
            if check(x, y + 1):
                move(x, y + 1)

        move(0,0)
        return self.count

if __name__ == '__main__':
    print(Solution().movingCount(3,2,17))
