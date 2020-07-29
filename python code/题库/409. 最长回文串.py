"""
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

from collections import defaultdict
from collections import Counter

class Solution:
    def mainFunc(self, s: str):
        return self.longestPalindrome_2(s)

    # hash表,效率低
    def longestPalindrome(self, s: str) -> int:
        count = 0
        flag = 0
        hashmap = defaultdict(lambda: 0)
        for i in range(len(s)):
            if s[i] in hashmap:
                hashmap[s[i]] += 1
            else:
                hashmap[s[i]] = 1
        for i in hashmap:
            count += (hashmap[i] // 2) * 2
            if not flag and hashmap[i] % 2:
                flag = 1
                count += 1
        return count

    def longestPalindrome_2(self, s: str) -> int:
        ans = 0
        count = Counter(s)
        for v in count.values():
            ans += v // 2 * 2
            if ans % 2 == 0 and v % 2 == 1:
                ans += 1
        return ans

if __name__ == '__main__':
    print(Solution().mainFunc("abccccdd"))

