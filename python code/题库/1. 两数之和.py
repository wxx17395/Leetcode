class Solution(object):
    # Hash表
    def twoSum(self, nums, target):
        key={}
        for i,v in enumerate(nums):
            if target-v in key:
                return [key[target-v],i]
            else:
                key[v]=i


    def twoSum1(self, nums, target):
        rlist = []
        for i in enumerate(nums):
            if target - nums[i[0]] in nums:
                if i[0] != nums.index(target - nums[i[0]]):
                    rlist.append(i[0])
                    rlist.append(nums.index(target - nums[i[0]]))
                    return rlist

if __name__=="__main__":
    print(Solution().twoSum([3, 3, 4, 15], 6))