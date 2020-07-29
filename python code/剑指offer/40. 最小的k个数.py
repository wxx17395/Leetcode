"""
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
 
限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

import heapq

class Solution:
    def getLeastNumbers(self, arr: list, k: int) -> list:
        if k == 0:
            return []
        heap = [-x for x in arr[:k]]
        heapq.heapify(heap)
        for i in range(k, len(arr)):
            if -heap[0] > arr[i]:
                heapq.heappop(heap)
                heapq.heappush(heap,-arr[i])
        res = [-x for x in heap]
        return res

