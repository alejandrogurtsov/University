import math

class Shape:
    def surface_area(self):
        raise NotImplementedError

    def volume(self):
        raise NotImplementedError

    def __str__(self):
        return f"{self.__class__.__name__}: Объём={self.volume():.2f}, Площадь поверхности={self.surface_area():.2f}"


class Cube(Shape):
    def __init__(self, side):
        self.side = side

    def surface_area(self):
        return 6 * self.side ** 2

    def volume(self):
        return self.side ** 3


class Sphere(Shape):
    def __init__(self, radius):
        self.radius = radius

    def surface_area(self):
        return 4 * math.pi * self.radius ** 2

    def volume(self):
        return (4/3) * math.pi * self.radius ** 3


class Cylinder(Shape):
    def __init__(self, radius, height):
        self.radius = radius
        self.height = height

    def surface_area(self):
        return 2 * math.pi * self.radius * (self.radius + self.height)

    def volume(self):
        return math.pi * self.radius ** 2 * self.height


class Parallelepiped(Shape):
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def surface_area(self):
        return 2 * (self.a*self.b + self.b*self.c + self.a*self.c)

    def volume(self):
        return self.a * self.b * self.c


class Ellipsoid(Shape):
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def surface_area(self):
        p = 1.6075
        return 4 * math.pi * ((self.a**p * self.b**p + self.a**p * self.c**p + self.b**p * self.c**p)/3)**(1/p)

    def volume(self):
        return (4/3) * math.pi * self.a * self.b * self.c


def check_shape(shapes):
    total_volume = sum(shape.volume() for shape in shapes)
    giants = [shape for shape in shapes if shape.volume() >= total_volume - shape.volume()]
    return giants

shapes = [
    Cube(3),
    Sphere(2),
    Cylinder(1, 5),
    Parallelepiped(2, 3, 4),
    Ellipsoid(2, 1, 3),
    Cube(10)
]

for shape in shapes:
    print(shape)

giants = check_shape(shapes)
print()
print("Фигуры с объёмом >= суммарного объёма остальных:")
for g in giants:
    print(g)
