strList = input("Введите слова: ").split()

dictionary = {}

for i in strList:
    if i in dictionary:
        print(dictionary[i], end = " ")
        dictionary[i] += 1
    else:
        print(0, end = " ")
        dictionary[i] = 1