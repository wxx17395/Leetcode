"""
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例:

s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution:
    def mainFuc(self, s:str):
        return self.decodeString(s)

    # 栈
    def decodeString(self, s: str) -> str:
        stack = []
        i = 0
        res = ''
        while i < len(s):
            curstr = ''
            kcount = 0
            if s[i] == '[':
                stack.append('[')
            elif '0' <= s[i] <= '9':
                while '0' <= s[i + kcount] <= '9':
                    kcount += 1
                stack.append(int(s[i:i + kcount]))
            elif 'a' <= s[i] <= 'z' or 'A' <= s[i] <= 'Z':
                if len(stack):
                    stack.append(s[i])
                else:
                    res += s[i]
            else:
                curc = stack.pop()
                while curc != '[':
                    curstr = curc + curstr
                    curc = stack.pop()
                curc = stack.pop()
                curstr *= curc
                # 若栈不空，将说明仍存在"[]"，将curstr再次压入栈中
                if not len(stack):
                    res += curstr
                else:
                    stack.append(curstr)
            i += 1 if kcount == 0 else kcount
        return res

if __name__ == '__main__':
    print(Solution().mainFuc("3[a]2[b4[F]c]"))





