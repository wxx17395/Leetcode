class Solution:
    # 递归，效率低
    def generateParenthesis1(self, n: int):
        res = []
        def genPar(curStr, l, r):
            if l == r and l > 0:
                genPar(curStr + '(', l - 1, r)
            elif l == r == 0:
                res.append(curStr)
                return
            else:
                if l > 0:
                    genPar(curStr + '(', l - 1, r)
                if r > 0:
                    genPar(curStr + ')', l, r - 1)
        genPar('', n, n)
        return res

    # 优化后的递归，修改了剪枝条件，类似DFS，效率是目前方法的最高
    def generateParenthesis2(self, n: int):
        res = []
        def genPar(curStr, l, r):
            if l < r or r > n or l > n:
                return
            if l == r == n:
                res.append(curStr)
                return
            genPar(curStr + '(', l + 1, r)
            genPar(curStr + ')', l, r + 1)
        genPar('', 0, 0)
        return res

    # 动态规划
    def generateParenthesis(self, n: int):
        if n == 0:
            return []
        total_l = []
        total_l.append([None])
        total_l.append(['()'])
        for i in range(2, n+1):
            l = []
            for j in range(i):
                now_list1 = total_l[j]
                now_list2 = total_l[i - 1 - j]
                for k1 in now_list1:
                    for k2 in now_list2:
                        if k1 == None:
                            k1 = ''
                        if k2 == None:
                            k2 = ''
                        el = '(' + k1 + ')' + k2
                        l.append(el)
            total_l.append(l)
        return total_l[n]


if __name__ == '__main__':
    print(Solution().generateParenthesis(3))