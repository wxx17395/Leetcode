class Solution:
    def convert(self, s: str, numRows: int) -> str:
        divisor = 2 * numRows - 2
        length = len(s)
        if not s and length == 0:
            return ''
        if divisor == 0:
            return  s
        newStr = ''
        while length % divisor != 0:
            s +=  '*'
            length += 1
        countZ = length // divisor
        for i in range(numRows):
            for j in range(countZ):
                if i == 0:
                    newStr += s[j * divisor]
                elif i == numRows - 1:
                    newStr += s[j * divisor + numRows - 1]
                else:
                    newStr += s[j * divisor + i] + s[j * divisor + divisor - i]
                #print(newStr)
        return newStr.replace('*', '')

if __name__ == '__main__':
    print(Solution().convert("LEETCODEISHIRING",1))
