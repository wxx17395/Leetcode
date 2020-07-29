# 类似DFS,建立树结构
class Solution:
    def letterCombinations(self, digits: str):
        dictBank = {'2':['a', 'b', 'c'], '3':['d', 'e', 'f'], '4':['g', 'h', 'i'],
                    '5':['j', 'k', 'l'], '6':['m', 'n', 'o'], '7':['p', 'q', 'r', 's'],
                    '8':['t', 'u', 'v'], '9':['w', 'x', 'y', 'z']}
        length = len(digits)
        result = []
        for i in range(length):
            if len(result) == 0:
                result = dictBank[digits[i]]
            else:
                midList = []
                for j in result:
                    for k in dictBank[digits[i]]:
                        midList.append(j + k)
                result = midList
        return result

if __name__ == '__main__':
    print(Solution().letterCombinations('23'))