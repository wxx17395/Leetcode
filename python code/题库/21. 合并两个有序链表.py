
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # 递归，60ms
    def mergeTwoLists(self, l1, l2):
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        if l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2

    # 归并,56ms
    def mergeTwoLists1(self, l1, l2):
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        resHead = ListNode(0)
        res = resHead
        while l1 != None and l2 !=None:
            if l1.val < l2.val:
                res.next = l1
                l1 = l1.next
            else:
                res.next = l2
                l2 = l2.next
            res = res.next
        if l1 == None:
            res.next = l2
        else:
            res.next = l1
        return resHead.next
