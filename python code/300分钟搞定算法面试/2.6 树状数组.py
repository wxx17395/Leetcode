class TreeArray:
    # 返回x的二进制第一个不为0的位置
    def __init__(self, A: list):
        self.A = A
        self.A.insert(0, 0)
        self.n = len(A)
        self.C = [0 for i in range(self.n)]
        self.autoUpdate()

    def lowbit(self, x: int) -> int:
        return x & (-x)

    # 计算数组前x的前缀和
    def getsum(self, x: int) -> int:
        res = 0
        while x > 0:
            res += self.C[x]
            x -= self.lowbit(x)
        return res

    def autoUpdate(self) -> None:
        for i in range(1, self.n):
            self.update(i, self.A[i])

    # 更新C[]数组
    def update(self, x: int, value: int) -> None:
        while x <= self.n:
            self.C[x] += value
            x += self.lowbit(x)

if __name__ == '__main__':
    test = TreeArray([1,10,11,100,101,110,111,1000])
    print(test.getsum(4))