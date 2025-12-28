class BankAccount:
    def __init__(self, balance=0):
        self.__balance = balance

    def get_balance(self):
        return self.__balance

    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount

    def withdraw(self, amount):
        if self.__balance < amount:
            raise ValueError("На счете недостаточно средств")
        else:
            self.__balance -= amount

    def transfer(self, account, amount):
        self.withdraw(amount)# если средств будет недостоточно, то
        # выйдет ошибка из метода withdraw (это чтобы не писать повторяющийся код)
        account.deposit(amount)

    def __str__(self):
        return f"{self.__balance}"

acc1 = BankAccount()
acc2 = BankAccount(100)
print(acc1.get_balance(), acc2.get_balance())

acc1.deposit(50)
acc2.deposit(-20)
print(acc1.get_balance(), acc2.get_balance())

try:
    acc1.withdraw(100)
    print(acc1.get_balance())
except ValueError as err:
    print(err)

acc2.transfer(acc1, 20)
print(acc1.get_balance(), acc2.get_balance())
