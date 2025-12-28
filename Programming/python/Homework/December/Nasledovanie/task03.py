class Product:
    def __init__(self, name, price, weight):
        self.__name = name
        self.__price = price
        self.__weight = weight

    @property
    def name(self):
        return self.__name

    @property
    def price(self):
        return self.__price

    @price.setter
    def price(self, value):
        self.__price = value

    @property
    def weight(self):
        return self.__weight

class Buy(Product):
    def __init__(self, name, price, weight, amount):
        super().__init__(name, price, weight)
        self.__amount = amount

    @property
    def amount(self):
        return self.__amount

    @amount.setter
    def amount(self, value):
        self.__amount = value

    @property
    def total_price(self):
        return self.price * self.amount

    @property
    def total_weight(self):
        return self.weight * self.amount

class Check(Buy):
    def print_info(self):
        print(f"Товар: {self.name}")
        print(f"Цена за единицу: {self.price}")
        print(f"Вес за единицу: {self.weight}")
        print(f"Количество: {self.amount}")
        print(f"Общая цена: {self.total_price}")
        print(f"Общий вес: {self.total_weight}")

check = Check("Шоколад", 140, 0.1, 5)
check.print_info()

check.amount = 10
check.price = 130
print("После изменения количества и цены:")
check.print_info()