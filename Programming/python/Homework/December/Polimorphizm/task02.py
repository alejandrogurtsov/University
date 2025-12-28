class Father:
    def __init__(self, mood='neutral'):
        self.mood = mood

    def greet(self):
        return "Hello!"

    def be_strict(self):
        self.mood = 'strict'

class Mother:
    def __init__(self, mood='normal'):
        self.mood = mood

    def greet(self):
        return "Hi, honey!"

    def be_kind(self):
        self.mood = 'kind'

class Daughter(Father, Mother):
    def __init__(self, mood='neutral'):
        super().__init__(mood)

class Son(Father, Mother):
    def __init__(self, mood='neutral'):
        super().__init__(mood)

son = Son()
son.be_kind()
print(f"Son mood after be_kind: {son.mood}")
son.be_strict()
print(f"Son mood after be_strict: {son.mood}")

daughter = Daughter()
daughter.be_kind()
print(f"Daughter mood after be_kind: {daughter.mood}")
daughter.be_strict()
print(f"Daughter mood after be_strict: {daughter.mood}")