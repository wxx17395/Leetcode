class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 :
            return False
        backupx = x
        reversedx = 0
        while x != 0:
            remainder = x % 10
            x = x // 10
            reversedx = reversedx * 10 + remainder
        if reversedx == backupx:
            return True
        else:
            return False


if __name__ == '__main__':
    print(Solution().isPalindrome(121))