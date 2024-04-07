inputFile = open("input.txt", "r")
inputList = [int(i) for i in inputFile.read().split()]
inputFile.close()

multiplication = 1
for i in inputList:
    multiplication *= i

outputFile = open("output.txt", "w")
outputFile.write(str(multiplication))
outputFile.close()