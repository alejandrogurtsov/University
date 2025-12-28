class Counter:
    def __init__(self, start=0):
        self.value = start

    def inc(self, amount=1):
        self.value += amount

    def dec(self, amount=1):
        if self.value - amount <= 0:
            self.value = 0
        else:
            self.value -= amount

    def __str__(self):
        return str(self.value)

class NonDecCounter(Counter):
    def dec(self, amount=1):
        pass

class LimitedCounter(Counter):
    def __init__(self, start=0, limit=10):
        self.limit = limit
        super().__init__(min(start, limit))

    def inc(self, n=1):
        self.value += n
        if self.value > self.limit:
            self.value = self.limit

c = Counter(5)
c.inc()
c.inc(3)
c.dec(4)
c.dec(10)
print(c.value)

ndc = NonDecCounter(5)
ndc.inc(5)
ndc.dec(100)
print(ndc.value)

lc = LimitedCounter(7, 10)
lc.inc()
lc.inc(10)
lc.dec(3)
print(lc.value)