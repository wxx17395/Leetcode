"""
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：

0 <= matrix.length <= 100
0 <= matrix[i].length <= 100
注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:
    def spiralOrder(self, matrix: list) -> list:
        if not matrix:
            return []
        n, m = len(matrix), len(matrix[0])
        x, y, count, cur = 0, -1, 0, 0
        toward = [(0,1),(1,0),(0,-1),(-1,0)]
        res = []
        while count < m * n:
            nx, ny = x + toward[cur][0], y + toward[cur][1]
            if 0 <= nx <= n-1 and 0 <= ny <= m-1 and matrix[nx][ny] != 'inf':
                res.append(matrix[nx][ny])
                matrix[nx][ny] = 'inf'
                x, y = nx, ny
                count += 1
            else:
                cur = (cur + 1) % 4
        return res

if __name__ == '__main__':
    print(Solution().spiralOrder([[1,2,3],[4,5,6],[7,8,9]]))