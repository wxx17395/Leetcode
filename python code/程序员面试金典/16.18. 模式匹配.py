"""
你有两个字符串，即pattern和value。 pattern字符串由字母"a"和"b"组成，用于描述字符串中的模式。例如，字符串"catcatgocatgo"匹配模式"aabab"（其中"cat"是"a"，"go"是"b"），该字符串也匹配像"a"、"ab"和"b"这样的模式。但需注意"a"和"b"不能同时表示相同的字符串。编写一个方法判断value字符串是否匹配pattern字符串。

示例 1：

输入： pattern = "abba", value = "dogcatcatdog"
输出： true
示例 2：

输入： pattern = "abba", value = "dogcatcatfish"
输出： false
示例 3：

输入： pattern = "aaaa", value = "dogcatcatdog"
输出： false
示例 4：

输入： pattern = "abba", value = "dogdogdogdog"
输出： true
解释： "a"="dogdog",b=""，反之也符合规则
提示：

0 <= len(pattern) <= 1000
0 <= len(value) <= 1000
你可以假设pattern只包含字母"a"和"b"，value仅包含小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pattern-matching-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:
    def patternMatching(self, pattern: str, value: str) -> bool:
        n = len(value)
        ca, cb = pattern.count('a'), pattern.count('b')
        i, j = 0, 0
        if ca < cb:
            ca, cb = cb, ca
            pattern= ''.join('a' if ch == 'b' else 'b' for ch in pattern)

        def check(i, j):
            sa , sb = '', ''
            c = 0
            for k in range(len(pattern)):
                if pattern[k] == 'a':
                    if sa == '':
                        sa = value[c: c + i]
                    elif sa != value[c: c + i]:
                        return False
                    c += i
                else:
                    if sb == '':
                        sb = value[c: c + j]
                    elif sb != value[c: c + j]:
                        return False
                    c += j
            return True if sa != sb else False

        if not value:
            return cb == 0
        if not pattern:
            return False

        while i < n // ca + 1:
            rest = n - ca * i
            if (cb == 0 and rest == 0) or (cb != 0 and rest % cb == 0):
                j = 0 if cb == 0 else rest // cb
                if check(i, j):
                    return True
            i += 1
        return False

if __name__ == '__main__':
    print(Solution().patternMatching("bbbaa", "aaaaaa"))