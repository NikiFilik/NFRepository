import csv
import random
import os

Filename = "Titanic.csv"

File = open(Filename, "r", newline = "")
reader = csv.DictReader(File)

data = []
for line in reader:
    data.append(line)

File.close()



def Show(*, type = "top", quantity = 5, separator = ','):
    if quantity > len(data):
        print("Function Show(), Error: not enough lines")
        return
    
    if type == "top":
        indiciesOfLinesToShow = [i for i in range(quantity)]
    elif type == "bottom":
        indiciesOfLinesToShow = [i for i in range(len(data) - quantity, len(data))]
    elif type == "random":
        indiciesOfLinesToShow = []
        indiciesPool = [i for i in range(len(data))]
        while(len(indiciesOfLinesToShow) < quantity):
            index = random.randint(0, len(indiciesPool) - 1)
            indiciesOfLinesToShow.append(indiciesPool[index])
            indiciesPool.pop(index)
    else:
        print("Function Show(), Error: no such type")
        return
    
    columnWidth = {}
    for keys in data[0]:
        columnWidth[keys] = len(keys)
    for i in indiciesOfLinesToShow:
        for keys in data[i]:
            columnWidth[keys] = max(columnWidth[keys], len(data[i][keys]))
    
    header = [keys for keys in data[0]]

    for keys in columnWidth:
        if keys != header[len(header) - 1]:
            print(keys + " " * (columnWidth[keys] - len(keys)), end = separator)
        else:
            print(keys + " " * (columnWidth[keys] - len(keys)))
    for i in indiciesOfLinesToShow:
        for keys in data[i]:
            if keys != header[len(header) - 1]:
                print(data[i][keys] + " " * (columnWidth[keys] - len(data[i][keys])), end = separator)
            else:
                print(data[i][keys] + " " * (columnWidth[keys] - len(data[i][keys])))



def Info():
    qtyNonEmptyValues = {}
    for keys in data[0]:
        qtyNonEmptyValues[keys] = 0
    for i in data:
        for keys in i:
            if i[keys] != "":
                qtyNonEmptyValues[keys] += 1
    
    valueType = {"PassengerId":"int", 
                 "Survived":"bool", 
                 "Pclass":"int", 
                 "Name":"str", 
                 "Sex":"str", 
                 "Age":"float", 
                 "SibSp":"int", 
                 "Parch":"int", 
                 "Ticket":"str", 
                 "Fare":"float", 
                 "Cabin":"str", 
                 "Embarked":"str"}
    
    print(len(data), "x" , len(data[0]), sep = "")
    for keys in qtyNonEmptyValues:
        print(keys, qtyNonEmptyValues[keys], valueType[keys], sep = " ")



def DelNaN():
    i = 0
    while(i != len(data)):
        needToDelete = False
        for keys in data[i]:
            if data[i][keys] == "":
                needToDelete = True
                break
        if needToDelete:
            data.pop(i)
        else:
            i += 1

def MakeDS():
    if not os.path.exists("workdata"):
        os.mkdir("workdata")
    if not os.path.exists("workdata/Learning"):
        os.mkdir("workdata/Learning")
    if not os.path.exists("workdata/Testing"):
        os.mkdir("workdata/Testing")

    trainFilename = "workdata/Learning/train.csv"
    testFilename = "workdata/Testing/test.csv"

    trainFile = open(trainFilename, "w", newline = "")
    testFile = open(testFilename, "w", newline = "")

    header = [keys for keys in data[0]]
    trainWriter = csv.DictWriter(trainFile, fieldnames = header)
    testWriter = csv.DictWriter(testFile, fieldnames = header)

    trainWriter.writeheader()
    testWriter.writeheader()

    for i in data:
        seed = random.randint(1, 10)
        if seed <= 7:
            trainWriter.writerow(i)
        else:
            testWriter.writerow(i)

    trainFile.close()
    testFile.close()



#Show()
#Info()
#DelNaN()
#MakeDS()
input("Press Enter to exit\n")