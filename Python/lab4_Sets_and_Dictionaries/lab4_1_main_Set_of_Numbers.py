print("Введите список целых чисел:")
numList = [int(i) for i in input().split()]

numSet = set(numList)

print("Количество различных чисел в списке:")
print(len(numSet))