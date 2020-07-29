# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 双指针法
class Solution:
    def removeNthFromEnd(self, head, n: int):
        firstNode = head
        secondNode = head
        preNode = None
        for i in range(n - 1):
            secondNode = secondNode.next

        while secondNode.next != None:
            preNode = firstNode
            firstNode = firstNode.next
            secondNode = secondNode.next
        if preNode == None:
            head = head.next
        else:
            preNode.next = firstNode.next
        return head
