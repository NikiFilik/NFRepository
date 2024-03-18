strList = input("Введите слова: ").split()

dictionary = {}

for i in strList:
    if i in dictionary:
        dictionary[i] += 1
    else:
        dictionary[i] = 1

print("Итог:", dictionary)