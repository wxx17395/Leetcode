"""
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
 

限制：

0 <= s 的长度 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:
    def mainFunc(self, s: str) -> str:
        #s.replace(' ','%20')
        return self.replaceSpace(s)


    def replaceSpace(self, s: str) -> str:
        list_s = list(s)
        for i in range(len(list_s)):
            if list_s[i] == ' ':
                list_s[i] = '%20'
        return ''.join(list_s)

if __name__ == '__main__':
    print(Solution().mainFunc("We are happy."))