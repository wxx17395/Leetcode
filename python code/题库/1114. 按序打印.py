from threading import Lock
class Foo:
    def __init__(self):
        self.FirstjobDone = Lock()
        self.SecondjobDone = Lock()
        self.FirstjobDone.acquire()
        self.SecondjobDone.acquire()
        pass

    def first(self, printFirst: 'Callable[[], None]') -> None:
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.FirstjobDone.release()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        # printSecond() outputs "second". Do not change or remove this line.
        with self.FirstjobDone:
            printSecond()
            self.SecondjobDone.release()

    def third(self, printThird: 'Callable[[], None]') -> None:
        # printThird() outputs "third". Do not change or remove this line.
        with self.SecondjobDone:
            printThird()