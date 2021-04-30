class Foo:
    def __init__(self):
        self._first = False
        self._second = False


    def first(self, printFirst: 'Callable[[], None]') -> None:
        
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self._first = True


    def second(self, printSecond: 'Callable[[], None]') -> None:
        while not self._first:
            pass
        # printSecond() outputs "second". Do not change or remove this line.
        printSecond()
        self._second = True

    def third(self, printThird: 'Callable[[], None]') -> None:
        while not self._second:
            pass
        # printThird() outputs "third". Do not change or remove this line.
        printThird()
        
#         Runtime: 3112 ms, faster than 5.01% of Python3 online submissions for Print in Order.
# Memory Usage: 14.7 MB, less than 67.53% of Python3 online submissions for Print in Order.
