from collections import Counter
from collections import defaultdict

class Solution:
    # 滑动窗口
    def minWindow(self, s: str, t: str) -> str:
        slen = len(s)
        minstart, minend, minlen = 0, 0, slen + 1
        left, right = 0, 0
        target = Counter(t)
        counter = defaultdict(lambda :0)

        def contains(counter, target):
            if len(counter) < len(target):
                return False
            for k in counter:
                if k not in target or counter[k] < target[k]:
                    return False
            return True

        for right in range(slen):
            if s[right] in target:
                counter[s[right]] += 1
            while left < slen and contains(counter, target):
                if minlen > right - left + 1:
                    minstart, minend, minlen = left, right, right - left + 1
                if s[left] in target:
                    counter[s[left]] -= 1
                left += 1

        return "" if minlen == slen + 1 else s[minstart: minend + 1]


if __name__ == '__main__':
    print(Solution().minWindow("ADOBECODEBANC", "ABC"))