class Solution:
    # 二分查找
    def findDuplicate(self, nums: list) -> int:
        n = len(nums)
        l, r, res = 1, n - 1, -1
        while l < r:
            mid = (l + r) // 2
            count = 0
            for i in range(n):
                count += 1 if nums[i] <= mid else 0
            if count <= mid:
                l = mid + 1
            else:
                r = mid - 1
                res = mid
        return res

if __name__ == '__main__':
    print(Solution().findDuplicate([1,3,4,2,2]))