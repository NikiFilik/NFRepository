inputFile = open("input.txt", "r")
inputList = [int(i) for i in inputFile.read().split()]
inputFile.close()

inputList.sort()

outputFile = open("output.txt", "w")
outputFile.writelines([str(i) + "\n" for i in inputList])
outputFile.close()