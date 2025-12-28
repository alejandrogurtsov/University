class Shape:
    def __init__(self, x,y):
        self.x = x
        self.y = y

    def move(self, dx, dy):
        self.x += dx
        self.y += dy

    def __str__(self):
        return f"({self.x};{self.y})"

class Circle(Shape):
    def __init__(self, x, y, r):
        super().__init__(x,y)
        if r>0:
            self.r = r
        else:
            raise ValueError()

    def __str__(self):
        return super().__str__() + f"radius: {self.r}"


c1 = Circle(3,5,10)
print(c1)