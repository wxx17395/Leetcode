class Solution:
    def romanToInt(self, s: str) -> int:
        romans = { "M":1000, "CM":900, "D":500, "CD":400, "C":100, "XC":90, "L":50, "XL":40, "X":10, "IX":9, "V":5, "IV":4, "I":1 }
        current = 0
        result = 0
        while current < len(s):
            if current + 1 < len(s) and s[current:current+2] in romans:
                result += romans[s[current:current+2]]
                current += 2
            else:
                result += romans[s[current]]
                current += 1
        return result



if __name__ == '__main__':
    print(Solution().romanToInt("MCMXCIV"))



