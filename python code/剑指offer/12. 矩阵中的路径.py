"""
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
提示：

1 <= board.length <= 200
1 <= board[i].length <= 200
注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:
    # DFS + 回溯法
    def exist(self, board: list, word: str) -> bool:
        n = len(board)
        m = len(board[0])
        moved = [[0 for i in range(m)] for j in range(n)]
        toward = [(0,1),(1,0),(0,-1),(-1,0)]
        def DFS(i, j, index, amoved):
            amoved[i][j] = 1
            if index == len(word) - 1:
                return True
            index += 1
            for xy in toward:
                x = i + xy[0]
                y = j + xy[1]
                if x < 0 or x >= n or y < 0 or y >= m or amoved[x][y] or board[x][y] != word[index]:
                    continue
                else:
                    if DFS(x, y, index, amoved):
                        return True
            amoved[i][j] = 0
            return False

        for i in range(n):
            for j in range(m):
                if board[i][j] == word[0]:
                    if DFS(i, j, 0, moved):
                        return True
        return False

if __name__ == '__main__':
    print(Solution().exist([["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]],"ABCESEEEFS"))