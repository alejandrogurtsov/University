import requests

api_key = '5308b1c549416d9dfbd35629ae4b3c93'
url = 'https://api.openweathermap.org/data/2.5/weather'

def weather(city):
    params = {
        "q": city,
        "appid": api_key,
        "units": "metric",
        "lang": "ru"
    }

    try:
        response = requests.get(url, params=params)
        data = response.json()

        main = data['main']
        wind = data['wind']
        weather_data = data['weather'][0]

        print("\nПрогноз погоды ")
        print(f"Город: {data['name']}")
        print(f"Погода: {weather_data['description']}")
        print(f"Температура: {main['temp']}°C")
        print(f"Ощущается как: {main['feels_like']}°C")
        print(f"Влажность: {main['humidity']}%")
        print(f"Скорость ветра: {wind['speed']} м/с")
        print(f"Давление: {main['pressure']} гПа")

    except requests.exceptions.RequestException:
        print("Ошибка в запросе")

city = input("Введите название города: ")
weather(city)