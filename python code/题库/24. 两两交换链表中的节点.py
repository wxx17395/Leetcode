
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # 非递归方法
    def swapPairs(self, head: ListNode) -> ListNode:
        newHead = ListNode(0)
        newHead.next = head
        preNode = newHead
        nextNode = head.next if head != None else None
        while head and nextNode:
             preNode.next = nextNode
             head.next = nextNode.next
             nextNode.next = head
             preNode = head
             head = head.next
             nextNode = head.next if head != None else None
        return newHead.next

    # 递归方法
    def swapPairs(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head

        l1 = head.next
        head.next = self.swapPairs(head.next.next)
        l1.next = head

        return l1
