"""
给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。

只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 

示例 1：

输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
示例 2：

输出：["b==a","a==b"]
输入：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
示例 3：

输入：["a==b","b==c","a==c"]
输出：true
示例 4：

输入：["a==b","b!=c","c==a"]
输出：false
示例 5：

输入：["c==c","b==d","x!=z"]
输出：true
 
提示：

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] 和 equations[i][3] 是小写字母
equations[i][1] 要么是 '='，要么是 '!'
equations[i][2] 是 '='

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/satisfiability-of-equality-equations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
class Solution:
    # 并查集
    class UnionFinde:
        def __init__(self):
            self.parent = list(range(26))

        def find(self, index):
            if index == self.parent[index]:
                return index
            self.parent[index] = self.find(self.parent[index])
            return self.parent

        def union(self, index1, index2):
            self.parent[self.find(index1)] = self.find(index2)

    def equationsPossible(self, equations: list) -> bool:
        uf = Solution.UnionFinde()
        for st in equations:
            if st[1] == '=':
                index1 = ord(st[0]) - ord('a')
                index2 = ord(st[3]) - ord('a')
                uf.union(index1, index2)
        for st in equations:
            if st[1] == '!':
                index1 = ord(st[0]) - ord('a')
                index2 = ord(st[3]) - ord('a')
                if uf.find(index1) == uf.find(index2):
                    return False
        return True

class Solution2:
    # 无向图染色法
    def equationsPossible(self, equations: list) -> bool:
        if not equations:
            return True
        graph = [[] for i in range(26)]
        for e in equations:
            if e[1] == '=':
                i = ord(e[0]) - ord('a')
                j = ord(e[3]) - ord('a')
                graph[i].append(j)
                graph[j].append(i)

        def bfs(node, color, colors, graph):
            queue = []
            visited = []
            queue.append(node)
            while queue:
                cur = queue.pop(0)
                colors[cur] = color
                visited.append(cur)
                for i in graph[cur]:
                    if i not in visited:
                        queue.append(i)

        colors = [0] * 26
        color = 1
        for i in range(26):
            if colors[i] == 0:
                bfs(i, color, colors, graph)
                color += 1

        for e in equations:
            if e[1] == '!':
                i = ord(e[0]) - ord('a')
                j = ord(e[3]) - ord('a')
                if colors[i] == colors[j]:
                    return False
        return True

if __name__ == '__main__':
    print(Solution2().equationsPossible(["c==c","b==d","x!=z"]))

