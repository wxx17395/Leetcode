"""
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

示例 1:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
 

提示：

0 < grid.length <= 200
0 < grid[0].length <= 200

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:
    def __init__(self):
        self.res = 0

    # dfs + 回溯 超时
    def maxValue_1(self, grid: 'list') -> int:
        if not grid and not grid[0]:
            return 0
        m , n = len(grid), len(grid[0])
        i , j = 0, 0

        def dfs(cur, i, j):
            cur += grid[i][j]
            if i == m - 1 and j == n -1:
                self.res = max(self.res, cur)
                return
            if i + 1 < m:
                dfs(cur, i + 1, j)
            if j + 1 < n:
                dfs(cur, i, j + 1)
        dfs(0, 0, 0)
        return self.res

    # 动归
    def maxValue(self, grid: 'list') -> int:
        m, n = len(grid), len(grid[0])
        for i in range(1, m):
            grid[i][0] += grid[i - 1][0]
        for j in range(1, n):
            grid[0][j] += grid[0][j - 1]
        for i in range(1,m):
            for j in range(1, n):
                grid[i][j] += max(grid[i - 1][j], grid[i][j - 1])
        return grid[-1][-1]


if __name__ == '__main__':
    print(Solution().maxValue([
  [1,3,1],
  [1,5,1],
  [4,2,1]
]))
