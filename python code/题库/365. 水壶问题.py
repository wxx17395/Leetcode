class Solution:
    # 求解ax+by=z，当且仅当z是gcd(x,y)的倍数时有解
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if x + y < z:
            return False
        if not x or not y:
            return z == 0 or z == x + y
        return z % self.gcd(x, y) == 0

    def gcd(self, x, y):
        if x < y:
            return self.gcd(y, x)
        while y != 0:
            temp = x % y
            x ,y = y, temp
        return  x


if __name__ == '__main__':
    print(Solution().canMeasureWater(3, 5, 4))