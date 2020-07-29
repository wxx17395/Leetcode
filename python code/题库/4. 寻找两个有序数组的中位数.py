class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        len1 = len(nums1)
        len2 = len(nums2)
        totalLen = len1 + len2
        tempList = []
        if ((len1 + len2) % 2 == 0):
            flag = True
        else:
            flag = False
        countTimes = totalLen // 2 + 1
        i = 0
        j = 0
        k = 0

        if (len1 == 0):
            tempList = nums2
        if (len2 == 0):
            tempList = nums1

        while (i < len1 and j < len2 and k < countTimes):
            if (nums1[i] <= nums2[j]):
                tempList.append(nums1[i])
                i += 1
            else:
                tempList.append(nums2[j])
                j += 1
            if (i == len1):
                tempList.extend(nums2[j:])
            if (j == len2):
                tempList.extend(nums1[i:])
            k += 1
        if flag:
            return (tempList[countTimes - 1] + tempList[countTimes - 2]) / 2
        else:
            return tempList[countTimes - 1]

    # 二分法查找
    def findMedianSortedArrays(self, nums1, nums2) -> float:
        n1, n2 = len(nums1), len(nums2)
        if n1 > n2 :
            return  self.findMedianSortedArrays(nums2, nums1)
        k = ( n1 + n2 + 1) // 2
        left, right = 0, n1
        while left < right :
            m1 = left + ( right - left) // 2
            m2 = k - m1
            if nums1[m1] < nums2[m2 - 1]:
                left = m1 + 1
            else:
                right = m1
        m1 = left
        m2 = k - m1
        if m1 > 0 and m2 > 0:
            c1 = max( nums1[m1 - 1], nums2[m2 - 1])
        elif m1 == 0:
            c1 = nums2[m2 - 1]
        else:
            c1 = nums1[m1 - 1]
        if ( n1 + n2 ) % 2 == 1:
            return c1
        if m1 < n1 and m2 < n2:
            c2 = min( nums1[m1], nums2[m2])
        elif m1 == n1:
            c2 = nums2[m2]
        else:
            c2 = nums1[m1]
        return ( c1 + c2 ) / 2

if __name__ == '__main__':
    print(Solution().findMedianSortedArrays([3,4],[1,2,3]))