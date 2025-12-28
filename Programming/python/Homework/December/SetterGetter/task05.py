class FoodInfo:
    def __init__(self, proteins, fats, carbohydrates):
        self.proteins = proteins
        self.fats = fats
        self.carbohydrates = carbohydrates

    def __repr__(self):
        return f"FoodInfo({self.proteins}, {self.fats}, {self.carbohydrates})"

    def __add__(self, other):
        if isinstance(other, FoodInfo):
            return FoodInfo(
                self.proteins + other.proteins,
                self.fats + other.fats,
                self.carbohydrates + other.carbohydrates
            )
        return NotImplemented

    def __mul__(self, n):
        if isinstance(n, (int, float)):
            return FoodInfo(
                self.proteins * n,
                self.fats * n,
                self.carbohydrates * n
            )
        return NotImplemented

    __rmul__ = __mul__

    def __truediv__(self, n):
        if isinstance(n, (int, float)) and n != 0:
            return FoodInfo(
                self.proteins / n,
                self.fats / n,
                self.carbohydrates / n
            )
        return NotImplemented

    def __floordiv__(self, n):
        if isinstance(n, (int, float)) and n != 0:
            return FoodInfo(
                self.proteins // n,
                self.fats // n,
                self.carbohydrates // n
            )
        return NotImplemented

cottage_cheese = FoodInfo(20, 5, 4)
jam = FoodInfo(0, 0, 25)

dessert = cottage_cheese + jam
print(dessert)

double_cottage_cheese = cottage_cheese * 2
print(double_cottage_cheese)

half_jam = jam / 2
print(half_jam)

third_cottage_cheese = cottage_cheese // 3
print(third_cottage_cheese)
