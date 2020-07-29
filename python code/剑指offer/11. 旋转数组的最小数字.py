"""
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：

输入：[3,4,5,1,2]
输出：1
示例 2：

输入：[2,2,2,0,1]
输出：0
注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

class Solution:
    # 二分查找的特殊形式
    def minArray(self, numbers: list) -> int:
        l, r = 0, len(numbers) - 1
        while l < r:
            cur = l + (r - l) // 2
            if numbers[cur] > numbers[r]:
                l = cur + 1
            elif numbers[cur] < numbers[r]:
                r = cur
            else:
                r = r - 1
        return numbers[l]

if __name__ == '__main__':
    print(Solution().minArray([3,1,3]))