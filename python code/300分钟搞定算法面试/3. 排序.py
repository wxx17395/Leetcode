class Sort:
    # 冒泡排序
    def bubbleSort(self, nums : 'list'):
        hasChange = True
        for i in range(len(nums) - 1):
            hasChange = False
            for j in range(len(nums) - 1 - i):
                if nums[j] > nums[j + 1]:
                    nums[j], nums[j + 1] = nums[j + 1], nums[j]
                    hasChange = True
            if not hasChange:
                break
        return nums

    # 插入排序
    def insertSort(self, nums : 'list'):
        i, j, current = 1, 0, 0
        for i in range(1, len(nums)):
            current = nums[i]
            for j in range(i - 1, -1, -1):
                if nums[j] > current:
                    nums[j + 1] = nums[j]
                    nums[j] = current
                else:
                    break
        return nums

    # 归并排序
    def mergeSort(self, nums : 'list'):
        def merge(left, right):
            r, l = 0, 0
            result = []
            while l < len(left) and r < len(right):
                if left[l] < right[r]:
                    result.append(left[l])
                    l += 1
                else:
                    result.append(right[r])
                    r += 1
            result += left[l:]
            result += right[r:]
            return result

        if len(nums) <= 1:
            return nums
        mid = len(nums) // 2
        left = self.mergeSort(nums[ : mid])
        right = self.mergeSort(nums[mid : ])
        return merge(left, right)

    # 快速排序
    def quickSort(self, nums: 'list'):
        def partition(l, h):
            i, j = l, h
            if i >= j:
                return
            temp = nums[i]
            while i < j:
                while i < j and nums[j] >= temp:
                    j -= 1
                nums[i] = nums[j]
                while i < j and nums[i] <= temp:
                    i += 1
                nums[j] = nums[i]
            nums[i] = temp
            partition(l, i - 1)
            partition(j + 1, h)
        partition(0, len(nums) - 1)
        return nums

    # 堆排序（？）
    def heapSort(self, nums: 'list'):
        def heapAdjust(parent, n):
            temp = nums[parent]
            child = 2 * parent + 1
            while child < n:
                if child + 1 < n and nums[child] < nums[child + 1]:
                    child += 1
                if temp > nums[child]:
                    break
                nums[parent] = nums[child]
                parent = child
                child = 2 * child + 1
            nums[parent] = temp

        n = len(nums)
        for i in range(n // 2)[::-1]:
            heapAdjust(i,n)
        for j in range(1,n)[::-1]:
            nums[0], nums[j] = nums[j], nums[0]
            heapAdjust(0,j)
        return nums


if __name__ == '__main__':
    print(Sort().heapSort([50, 123, 543, 187, 49, 30, 0, 2, 11, 100]))