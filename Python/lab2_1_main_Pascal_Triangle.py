#Функция нахождения длины числа
def len(n):
    ans = 0
    while(n > 0):
        ans += 1
        n = n // 10
    return ans

n = int(input("Введите N: "))

#Создание двумерного списка для хранения чисел
a = [[0] * n for i in range(n)]
a[0][0] = 1

#Запоминаем максимум, дабы пробелами сделать красивый вывод
mx = 1

#Находим все значения в треугольнике Паскаля, учитывая, что каждый элемент равен сумме верхних элементов смежных с ним
for i in range(n - 1):
    for j in range(i + 1):
        a[i + 1][j] += a[i][j]
        mx = max(mx, a[i + 1][j])

        a[i + 1][j + 1] += a[i][j]
        mx = max(mx, a[i + 1][j + 1])

#Задаем длину одному числу с пробелами
cnt = len(mx) + 1
if cnt % 2 == 1:
    cnt += 1

#Вывод
if n % 2 == 0:
    for i in range(n):
        if (i % 2 == 0):
            print(" " * (cnt // 2) + " " * cnt * ((n - i - 2) // 2), end="")
        else:
            print(" " * cnt * ((n - i - 1) // 2), end="")
        for j in range(i + 1):
            print(" " * (cnt - len(a[i][j])), end="")
            print(a[i][j], end="")
        print()
else:
    for i in range(n):
        if (i % 2 == 0):
            print(" " * cnt * ((n - i - 1) // 2), end = "")
        else:
            print(" " * (cnt // 2) + " " * cnt * ((n - i - 2) // 2), end = "")
        for j in range(i + 1):
            print(" " * (cnt - len(a[i][j])), end = "")
            print(a[i][j], end = "")
        print()
