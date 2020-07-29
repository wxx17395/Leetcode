# 贪心算法
class Solution:
    def intToRoman(self, num: int) -> str:
        nums = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        romans = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        index = 0
        result = ""
        while index < 13 :
            while num >= nums[index]:
                result += romans[index]
                num -= nums[index]
            index += 1
        return result

if __name__ == '__main__':
    print(Solution().intToRoman(666))



