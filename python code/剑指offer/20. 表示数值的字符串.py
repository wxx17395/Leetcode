"""
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"、"-1E-16"及"12e+5.4"都不是。

注意：本题与主站 65 题相同：https://leetcode-cn.com/problems/valid-number/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:
    def isNumber(self, s: str) -> bool:
        if not s:
            return False
        s = s.strip(' ')
        numSeen, dotSeen, eSeen = False, False, False
        for i in range(len(s)):
            if '0' <= s[i] <= '9':
                numSeen = True
            elif s[i] == '.':
                if dotSeen or eSeen:
                    return False
                dotSeen = True
            elif s[i] == 'e':
                if eSeen or not numSeen:
                    return False
                eSeen, numSeen = True, False
            elif s[i] in ['-', '+']:
                if i != 0 and s[i - 1] != 'e' and s[i - 1] != 'E':
                    return False
            else:
                return False
        return numSeen

if __name__ == '__main__':
    print(Solution().isNumber('0'))