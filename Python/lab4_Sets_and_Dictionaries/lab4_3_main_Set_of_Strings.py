n = int(input("Введите число городов за сеанс игры: "))
citySet = set()

print("Вводите названия городов по одному")
while len(citySet) < n:
    cityName = input()

    if cityName in citySet:
        print("REPEAT")
    else:
        print("OK")
        citySet.add(cityName)

print("Игра окончена!")