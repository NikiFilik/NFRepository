import numpy as np
import random

def task1():
    inputFile = open("input_task1.txt", "r")
    matrix = np.array([[int(j) for j in i.split(", ")] for i in inputFile.read().split("\n")])
    inputFile.close()

    print("Sum of matrix:", matrix.sum())
    print("Max of matrix:", matrix.max())
    print("Min of matrix:", matrix.min())



def task2():
    x = np.array([random.randint(1, 2) for i in range(random.randint(10, 50))])

    a = []
    b = []

    lastNum = x[0]
    lastNumCnt = 1
    for i in range(1, len(x)):
        if x[i] == lastNum:
            lastNumCnt += 1
        else:
            a.append(lastNum)
            b.append(lastNumCnt)
            lastNum = x[i]
            lastNumCnt = 1
    a.append(lastNum)
    b.append(lastNumCnt)
    
    output = (np.array(a), np.array(b))

    print("Input:", x)
    print("Output:", output)



def task3():
    data = np.array([[int(random.normalvariate(mu=0.0, sigma=100.0)) for j in range(4)] for i in range(10)])

    standartnoeOtklonenie = ((np.array([((i - (data.sum() / data.size)) ** 2) for i in data]).sum()) * (1 / data.size)) ** 0.5

    print("Data:", data)
    print("Min value:", data.min())
    print("Max value:", data.max())
    print("Mid value:", data.sum() / data.size)
    print("Standartnoe otklonenie:", standartnoeOtklonenie)

    first5Lines = data[0:5]



def task4():
    x = np.array([random.randint(0, 10) for i in range(random.randint(0, 100))])

    mx = -1
    for i in range(1, x.size):
        if x[i - 1] == 0:
            mx = max(mx, x[i])
    
    print("Array X:", x)
    print("Maximum:", mx)



def task5():
    print()



def task6():
    a = np.arange(16).reshape(4, 4)
    print("Array a:")
    print(a)

    temp = a[0].copy()
    a[0] = a[2]
    a[2] = temp

    print("Changed Array a:")
    print(a)



def task7():
    url = "https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data"
    iris = np.genfromtxt(url, delimiter=",", dtype = "object")
    uniqueSpecies = []

    for i in iris:
        if i[4] not in uniqueSpecies:
            uniqueSpecies.append(i[4])
    
    print("Unique Species:", uniqueSpecies)
    print("Number of Unique Species:", len(uniqueSpecies))



def task8():
    x = [random.randint(0, 10) for i in range(random.randint(0, 100))]
    noNullIndicies = []

    for i in range(len(x)):
        if x[i] != 0:
            noNullIndicies.append(i)
    
    print("Array X:", x)
    print("No Null Indicies:", noNullIndicies)



#task1()
#task2()
#task3()
#task4()
#task5()
#task6()
#task7()
#task8()