"""
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # 递归
    def isSymmetric_1(self, root: TreeNode) -> bool:
        def recursion(left: TreeNode, right: TreeNode):
            if not left and not right:
                return True
            if not left or not right or left.val != right.val:
                return False
            return recursion(left.left,right.right) and recursion(left.right,right.left)
        return recursion(root,root)

    # 迭代, 利用队列
    def isSymmetric(self, root: TreeNode) -> bool:
        queue = []
        queue.append(root)
        queue.append(root)
        while queue:
            u = queue.pop(0)
            v = queue.pop(0)
            if not u and not v:
                continue
            if not u or not v or u.val != v.val:
                return False
            queue.append(u.left)
            queue.append(v.right)
            queue.append(u.right)
            queue.append(v.left)
        return True

if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(2)
    # root.left.left = None
    # root.left.right = TreeNode(3)
    # root.right.left = None
    # root.right.right = TreeNode(3)
    print(Solution().isSymmetric(root))