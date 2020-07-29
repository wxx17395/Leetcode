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

if __name__ == '__main__':
    root = create_tree([5, 4, 8, 11, None, 13, 4, 7, 2, None, None, 5, 1])