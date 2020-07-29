# 这道题用python做不是算法思想，正确做法是循环将x对10取余和取模，
class Solution:
    def reverse(self, x: int) -> int:
        strX = str(x)
        list1 = list(strX)
        negativeFlag = False
        if list1[0] == '-':
            negativeFlag = True
            negative = list1.pop(0)
        list1.reverse()
        if negativeFlag:
            list1.insert(0, negative)
        reversedXstr = ''.join(list1)
        reversedX = int(reversedXstr)
        if reversedX > 2 ** 31 - 1 or reversedX < -2 ** 31:
            return 0
        else:
            return reversedX

if __name__ == '__main__':
    print(Solution().reverse(9876))