class nQueen:
    def __init__(self, n: int):
        self.n = n
        self.column = [None for i in range(n)]
        self.count = 0
        self.mainFunc()

    def mainFunc(self):
        self.backTracking(0)
        print(self.count)


    def check(self, row, col):
        for r in range(row):
            if self.column[r] == col or (row - r) == abs(self.column[r] - col):
                    return False
        return True

    def backTracking(self, row: int):
        if row == self.n:
            self.count += 1
            return
        for col in range(self.n):
            self.column[row] = col
            if self.check(row, col):
                self.backTracking(row + 1)
            self.column[row] = -1

if __name__ == '__main__':
    print(nQueen(8))