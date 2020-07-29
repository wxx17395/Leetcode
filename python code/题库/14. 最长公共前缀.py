# 二分法
class Solution:
    def longestCommonPrefix(self, strs) -> str:
        minIndex = 0
        minLen = float('inf')
        if len(strs) == 0: return ''
        if len(strs) == 1: return strs[0]
        for i in range(len(strs)):
            if len(strs[i]) < minLen:
                minLen = len(strs[i])
                minIndex = i
        if strs[minIndex] == '': return ''
        left, right = 0, minLen
        while left < right:
            flag = 1
            mid = (right + left) // 2 + 1
            for i in range(len(strs)):
                if strs[i][left : mid] != strs[minIndex][left : mid]:
                    flag = 0
                    break
            if flag:
                left = mid
            else:
                right = mid - 1
        return strs[minIndex][:left]

if __name__ == '__main__':
    print(Solution().longestCommonPrefix(["cc","cc","ccc"]))
