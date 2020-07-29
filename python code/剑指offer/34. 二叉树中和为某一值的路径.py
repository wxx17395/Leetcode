"""
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]
 
提示：

节点总数 <= 10000
注意：本题与主站 113 题相同：https://leetcode-cn.com/problems/path-sum-ii/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from collections import deque


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
    def pathSum(self, root: TreeNode, sum: int) -> list:
        res,path = [], []

        def dfs(node,cursum):
            if not node:
                return
            path.append(node.val)
            cursum += node.val
            if cursum == sum and not node.left and not node.right:
                res.append(list(path))
            dfs(node.left, cursum)
            dfs(node.right, cursum)
            path.pop()
        dfs(root,0)
        return res



if __name__ == '__main__':
    root = create_tree([5,4,8,11,None,13,4,7,2,None,None,5,1])
    print(Solution().pathSum(root,22))
    # queue = [root]
    # while queue:
    #     node = queue.pop(0)
    #     print(node.val)
    #     if node.left:
    #         queue.append(node.left)
    #     if node.right:
    #         queue.append(node.right)


