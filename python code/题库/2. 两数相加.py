class Solution(object):
    def addTwoNumbers(self, l1, l2):
        rList = l1
        addflag = 0
        returnflag = 0
        while 1:
            if not l1.next or not l2.next:
                returnflag = 1
            addresult = l1.val + l2.val
            if addflag:
                addresult += 1
                addflag = 0
            if addresult > 9:
                addresult -= 10
                addflag = 1
            l1.val = addresult
            if returnflag:
                break
            l1 = l1.next
            l2 = l2.next
        if not l1.next and l2.next:
            l1.next = l2.next
        while addflag == 1:
            if not l1.next:
                newListNode = ListNode(0)
                l1.next = newListNode
                addflag = 0
            l1=l1.next
            tempvar = l1.val + 1
            if tempvar > 9:
                l1.val = tempvar - 10
            else:
                l1.val = tempvar
                addflag = 0
        return rList

    def addTwoNumbers(self, l1, l2):
        re = ListNode(0)
        r = re
        carry = 0
        while (l1 or l2):
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            s = carry + x + y
            carry = s // 10
            r.next = ListNode(s % 10)
            r = r.next
            if (l1 != None): l1 = l1.next
            if (l2 != None): l2 = l2.next
        if (carry > 0):
            r.next = ListNode(1)
        return re.next