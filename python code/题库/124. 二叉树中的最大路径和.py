"""
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

from collections import deque,defaultdict


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def create_tree(nodelist) -> TreeNode:
    root = TreeNode(nodelist[0])
    queue, i = deque(), 1
    queue.append(root)
    while queue and i < len(nodelist):
        node = queue.popleft()
        if nodelist[i]:
            left = TreeNode(nodelist[i])
            node.left = left
            queue.append(node.left)
        i += 1
        if nodelist[i]:
            right = TreeNode(nodelist[i])
            node.right = right
            queue.append(node.right)
        i += 1
    return root


class Solution:
    # 后序遍历
    def maxPathSum(self, root: TreeNode) -> int:
        self.res = float('-inf')

        def recursion(node) -> int:
            if not node:
                return 0

            left = max(recursion(node.left), 0)
            right = max(recursion(node.right), 0)

            cur = node.val + left + right

            self.res = max(self.res, cur)

            return node.val + max(left, right)

        recursion(root)
        return int(self.res)


if __name__ == '__main__':
    root = create_tree([5,4,8,11,None,13,4,7,2,None,None,None,1])
    print(Solution().maxPathSum(root))