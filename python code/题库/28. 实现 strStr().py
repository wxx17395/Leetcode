class Solution:
    # kmp算法
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == '':
            return 0
        i, j = 0, 0
        len1, len2 = len(haystack), len(needle)
        next = self.getNext(needle)
        while i < len1 and j < len2:
            if j == -1 or haystack[i] == needle[j]:
                i += 1
                j += 1
            else:
                j = next[j]
        if j == len2:
            return i - j
        return -1

    def getNext(self, str):
        length = len(str)
        next = [-1]
        j, k = 0, -1
        while j < length - 1:
            if k == -1 or str[k] == str[j]:
                j += 1
                k += 1
                if str[j] != str[k]:
                    next.append(k)
                else:
                    next.append(next[k])
            else:
                k = next[k]
        return next

if __name__ == '__main__':
    print(Solution().strStr("mississippi", "issip"))