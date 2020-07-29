"""
中心拓展算法
存在更优算法马拉车算法，未看
"""

class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)
        if not s and length == 0:
            return ''
        start, end = 0, 0
        for i in range(length):
            len1 = self.expandAroundCenter(s, i, i)
            len2 = self.expandAroundCenter(s, i, i+1)
            currentLen = max(len1, len2)
            if currentLen > (end - start + 1):
                start = i - (currentLen - 1) // 2
                end = i + currentLen // 2
        return  s[int(start) : int(end + 1)]

    def expandAroundCenter(self, s, left, right):
        length = len(s)
        while left >= 0 and right < length and s[left] == s[right]:
            left -= 1
            right += 1
        return (right - left - 1)

if __name__ == '__main__':
    print(Solution().longestPalindrome('ababa'))