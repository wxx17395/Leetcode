"""
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 
说明：

用返回一个整数列表来代替打印
n 为正整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:
    def printNumbers(self, n: int) -> list:
        def addString(trace, point):
            n = len(trace)
            temp = 0
            for i in range(n - 1, -1, -1):
                if i == n - 1:
                    temp += ord(trace[i]) - ord('0') + 1
                else:
                    temp += ord(trace[i]) - ord('0')
                trace[i] = str(temp % 10)
                if temp < 10:
                    break
                else:
                    temp = temp // 10
                    point += 1
            return point

        res = []
        trace = ['0'] * n
        start = 0
        while True:
            point = addString(trace, 0)
            for i in range(n):
                if trace[i] != '0':
                    start = i
                    break
            if point == n:
                break
            res.append(int(''.join(trace[start:])))
        return res

if __name__ == '__main__':
    print(Solution().printNumbers(2))
