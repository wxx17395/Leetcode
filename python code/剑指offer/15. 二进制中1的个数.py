"""
请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。

示例 1：

输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
示例 2：

输入：00000000000000000000000010000000
输出：1
解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
示例 3：

输入：11111111111111111111111111111101
输出：31
解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。

注意：本题与主站 191 题相同：https://leetcode-cn.com/problems/number-of-1-bits/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:
    # 计算二进制数时计算
    def hammingWeight_1(self, n: int) -> int:
        count = 0
        while n:
            count += 1 if n % 2 == 1 else 0
            n //= 2
        return count

    # 逐位判断
    def hammingWeight_2(self, n: int) -> int:
        count = 0
        while n:
            count += n & 1

        return count

    # 利用n&(n-1)的结果为n的二进制位表示中最低位的1变为0
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            n = n & (n - 1)
            count += 1
        return count

if __name__ == '__main__':
    print(Solution().hammingWeight(11))