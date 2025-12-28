class Bachelor:
    def __init__(self, firstName, lastName, group, averageMark):
        self.firstName = firstName
        self.lastName = lastName
        self.group = group
        self.averageMark = averageMark

    def getScholarship(self):
        if self.averageMark == 5:
            return 10000
        elif self.averageMark > 3:
            return 5000
        return 0

class Undergraduate(Bachelor):
    def __init__(self, firstName, lastName, group, averageMark, researchWork):
        super().__init__(firstName, lastName, group, averageMark)
        self.researchWork = researchWork

    def getScholarship(self):
        if self.averageMark == 5:
            return 15000
        elif self.averageMark > 3:
            return 7500
        return 0

students = [
    Bachelor("Ivan", "Ivanov", "B101", 5),
    Bachelor("Petr", "Petrov", "B102", 3.5),
    Undergraduate("Anna", "Smirnova", "M201", 5, "AI research"),
    Undergraduate("Olga", "Kuznetsova", "M202", 4, "Data analysis"),
    Undergraduate("Maxim", "Maximov", "M203", 3, "ML models")
]

for student in students:
    print(student.getScholarship())