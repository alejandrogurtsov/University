class Ndrob:
    def __init__(self, num, denom):
        self.num = num
        if denom != 0:
            self.denom = denom
        else:
            raise ValueError()

    def __str__(self):
        return f"{self.num}/{self.denom}"

    def isRight(self):
        if self.num >= self.denom:
            return False
        else:
            return True

    def multy(self, otherNdrob):
        if isinstance(otherNdrob, Ndrob):
            res = Ndrob(1,1)
            res.num = self.num * otherNdrob.num
            res.denom = self.denom * otherNdrob.denom
            return res
        else:
            raise ValueError()

    def setNum(self, num):
        self.num = num

    def getNum(self):
        return self.num


frac1 = Ndrob(3,5)
print(frac1)
print(frac1.isRight())
frac2 = Ndrob(5,7)
frac3 = frac1.multy(frac2)
print(frac3)

