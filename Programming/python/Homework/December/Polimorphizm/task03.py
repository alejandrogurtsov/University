from abc import ABC, abstractmethod

class Date(ABC):
    def __init__(self, year, month, day):
        self.year = year
        self.month = month
        self.day = day

    @abstractmethod
    def format(self):
        pass

    def iso_format(self):
        return f"{self.year}-{self.month:02d}-{self.day:02d}"

class USADate(Date):
    def __init__(self, year, month, day):
        super().__init__(year, month, day)

    def format(self):
        return f"{self.month:02d}-{self.day:02d}-{self.year}"

class ItalianDate(Date):
    def __init__(self, year, month, day):
        super().__init__(year, month, day)

    def format(self):
        return f"{self.day:02d}/{self.month:02d}/{self.year}"

usa = USADate(2025, 12, 21)
ita = ItalianDate(2025, 12, 21)

print(usa.format())
print(usa.iso_format())

print(ita.format())
print(ita.iso_format())