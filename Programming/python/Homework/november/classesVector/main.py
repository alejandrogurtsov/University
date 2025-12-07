from math import sqrt, atan2
class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"({self.x}, {self.y})"

    def length(self):
        return sqrt(self.x**2 + self.y**2)

    def angle(self):
        return atan2(self.y, self.x)

    def add(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def sub(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    def scal(self, other):
        return self.x * other.x + self.y * other.y

a = Vector(5, 9)
b = Vector(1, 3)

print("Длина вектора А:",a.length())
print("Угол наклона вектора B:",b.angle())
print("Сумма векторов A и B:",a.add(b))
print("Разность векторов B и A:",b.sub(a))
print("Скалярное произведение:",a.scal(b))
