print("Введите первое множество чисел:")
set1 = set([int(i) for i in input().split()])
print("Введите второе множество чисел:")
set2 = set([int(i) for i in input().split()])

flag = True
if set1 == set2:
    flag = False
else:
    for i in set1:
        if i not in set2:
            flag = False
            break
        
if flag:
    print("Первое множество является подмножеством второго")
else:
    print("Первое множество не является подмножеством второго")