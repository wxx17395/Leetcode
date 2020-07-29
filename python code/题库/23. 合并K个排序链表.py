
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # 2路归并
    def mergeKLists(self, lists):
        amount = len(lists)
        interval = 1
        while interval < amount:
            for i in range(0, amount - interval, interval * 2):
                lists[i] = self.mergeTwoLists(lists[i], lists[i + interval])
            interval *= 2
        return lists[0] if amount > 0 else lists

    def mergeTwoLists(self, l1, l2):
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        resHead = ListNode(0)
        res = resHead
        while l1 != None and l2 != None:
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
