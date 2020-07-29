# 不利用正则表达式需要考虑很多情况，利用正则表达式比较简单
import re
class Solution:
    def myAtoi(self, str: str) -> int:
        return max(min(int(*re.findall('^[\+\-]?\d+', str.lstrip())), 2 ** 31 - 1), -2 ** 31)

if __name__ == '__main__':
    print(Solution().myAtoi('0-1'))