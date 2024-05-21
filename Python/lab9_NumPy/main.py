import numpy as np
import random
import scipy
import time

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
    N = int(input("Enter the number of data: "))
    D = int(input("Enter the dimdension of data: "))

    m = np.array([random.randint(1, 100) for i in range(D)])
    X = np.array([np.array([random.randint(1, 100) for i in range(D)]) for j in range(N)])
    C = np.array([np.array([0 for i in range(D)]) for j in range(D)])
    while True:
        for i in range(D):
            for j in range(i + 1):
                C[i][j] = random.randint(1, 100)
                C[j][i] = C[i][j]
        
        #Checking that matrix C should be symmetric positive semidefinite
        flag = True
        for i in range(1, D + 1):
            temp = np.array([np.array([0 for k in range(i)]) for j in range(i)])
            
            for j in range(i):
                for k in range(i):
                    temp[j][k] = C[j][k]

            if np.linalg.det(temp) < 0:
                flag = False
        
        if flag:
            break

    
    def MyLnOfDensityMultivariateNormalDistributionFunction(D, X, m, C):
        return -(D/2) * np.log(2 * np.pi) - 0.5 * np.log(np.linalg.det(C)) - 0.5 * np.sum((X - m) @ np.linalg.inv(C) * (X - m), axis = 1)
    
    print("X:", X)
    print("m:", m)
    print("C:", C)
    print("My: ", MyLnOfDensityMultivariateNormalDistributionFunction(D, X, m, C))
    print("Scipy: ", scipy.stats.multivariate_normal(m, C).logpdf(X))

    #timer
    MyStart = time.time()
    for i in range(1000):
        MyLnOfDensityMultivariateNormalDistributionFunction(D, X, m, C)
    MyFinish = time.time()

    ScipyStart = time.time()
    for i in range(1000):
        scipy.stats.multivariate_normal(m, C).logpdf(X)
    ScipyFinish = time.time()

    print("My Time:", MyFinish - MyStart, "Scipy Time:", ScipyFinish - ScipyStart)



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