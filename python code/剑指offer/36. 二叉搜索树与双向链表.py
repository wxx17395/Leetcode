"""
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

为了让您更好地理解问题，以下面的二叉搜索树为例：

我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。

注意：本题与主站 426 题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

注意：此题对比原题有改动。

通过次数13,382提交次数21,467

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
from collections import deque
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return root
        stack, node, nodeList = [], root, []
        while stack or node:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            nodeList.append(node)
            node = node.right
        n = len(nodeList)
        for i in range(n):
            nodeList[i].left = nodeList[(i - 1) % n]
            nodeList[i].right = nodeList[(i + 1) % n]
        return nodeList[0]

def create_tree(nodelist) -> Node:
    root = Node(nodelist[0])
    queue, i = deque(), 1
    queue.append(root)
    while queue and i < len(nodelist):
        node = queue.popleft()
        if nodelist[i]:
            left = Node(nodelist[i])
            node.left = left
            queue.append(node.left)
        i += 1
        if nodelist[i]:
            right = Node(nodelist[i])
            node.right = right
            queue.append(node.right)
        i += 1
    return root

if __name__ == '__main__':
    root = create_tree([4,2,5,1,3])
    print(Solution().treeToDoublyList(root))

