"""
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

示例 1:

输入:
first = "pale"
second = "ple"
输出: True
 

示例 2:

输入:
first = "pales"
second = "pal"
输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/one-away-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:
    # 双指针,第一遍从前往后扫，第二遍从后往前扫，首次出现不同时记录位置并停止
    # 如果两个字符串出现不同的位置之差<1，则证明最多相差一个位置
    def oneEditAway(self, first: str, second: str) -> bool:
        if first == second:
            return True
        l1, l2 = len(first), len(second)
        if abs(l1 - l2) > 1:
            return False
        s, i, j = 0, l1 -1, l2 - 1
        while s < l1 and s < l2 and first[s] == second[s]:
            s += 1
        while i >= 0 and j >= 0 and first[i] == second[j]:
            i -= 1
            j -= 1
        return i - s < 1 and j - s < 1

if __name__ == '__main__':
    print(Solution().oneEditAway("pale", "plee"))