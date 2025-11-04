import json

def create(filename):
    users = {}
    n = int(input("Введите количество пользователей: "))

    for i in range(1, n+1):
        print(f"\nUser {i}:")
        login = input("Логин: ")
        last_online = input("Последний онлайн (в формате ЧЧ:ММ ДД.ММ.ГГГГ): ")
        duration = input("Продолжительность сессии (например, 4h 32min): \n")

        users[f'User{i}']={
            "login":login,
            "last online":last_online,
            "duration":duration
        }

    data = {"users":users}

    with open(filename, "w") as f:
        json.dump(data, f, ensure_ascii=True)

def read(filename):
    try:
        with open(filename, 'r') as f:
            data = json.load(f)
        for user, info in data["users"].items():
            print(f"{user}:")
            print(f"Логин: {info['login']}")
            print(f"Последний онлайн: {info['last online']}")
            print(f"Продолжительность сессии: {info['duration']}\n")

    except FileNotFoundError:
        print("Файл не найден")

def main():
    filename = "users.json"

    while True:
        print("Выберите действие:")
        print("1 - Создать JSON-файл")
        print("2 - Прочитать и вывести JSON-файл")
        print("0 - Выход")
        choice = input()

        if choice == "1":
            create(filename)
        elif choice == "2":
            read(filename)
        elif choice == "0":
            break
        else:
            print("Неверный выбор. Повторите ввод.")

main()