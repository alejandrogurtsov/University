class User:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, new_name):
        if new_name == "" or not new_name.isalpha():
            raise ValueError("Некорректное имя")
        self.__name = new_name

    @property
    def age(self):
        return self._age

    @age.setter
    def age(self, new_age):
        if not isinstance(new_age, int) or not (0 <= new_age <= 110):
            raise ValueError("Некорректный возраст")
        self._age = new_age

    def get_name(self):
        return self.name

    def set_name(self, new_name):
        self.name = new_name

    def get_age(self):
        return self.age

    def set_age(self, new_age):
        self.age = new_age

    def __str__(self):
        return f"{self.name} {self.age}"

u = User("Ivan", 20)
print(u.get_name(), u.get_age())

u.set_name("Petr")
print(u.get_name())

u.set_age(30)
print(u.get_age())

try:
    u.set_name("")
except ValueError as err:
    print(err)

try:
    u.set_name("Alex000")
except ValueError as err:
    print(err)

try:
    u.set_age(150)
except ValueError as err:
    print(err)