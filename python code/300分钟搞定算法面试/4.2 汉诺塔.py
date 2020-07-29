class hano:
    def move(self, n, from_which, buffer, to_which):
        if n==1:
            print('Move',n,'from',from_which,'to',to_which)
        else:
            self.move(n-1,from_which,to_which,buffer)
            self.move(1,from_which,buffer,to_which)
            self.move(n-1,buffer,from_which,to_which)

if __name__ == '__main__':
    hano().move(4, 'A', 'B', 'C')