n = int(input("Введите количество записей: "))

database = {}


for i in range(n):
    log = input().split()

    if log[0] not in database:
        database[log[0]] = {}

    if log[1] not in database[log[0]]:
        database[log[0]][log[1]] = int(log[2])
    else:
        database[log[0]][log[1]] += int(log[2])


print("Итог:")
for i in database.keys():
    print()
    print(i + ":")

    for j in database[i].keys():
        print(j + " - ", end = "")
        print(database[i][j])