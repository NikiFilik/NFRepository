inputFile = open("input.txt", "r")
inputList = [i.split() for i in inputFile.readlines()]
inputFile.close()

inputList.sort(key = lambda kid: kid[2])

theYoungestFile = open("the_youngest.txt", "w")
theYoungestFile.write(inputList[0][0] + " " + inputList[0][1] + " " + str(inputList[0][2]))
theYoungestFile.close()

theOldestFile = open("the_oldest.txt", "w")
theOldestFile.write(inputList[-1][0] + " " + inputList[-1][1] + " " + str(inputList[-1][2]))
theOldestFile.close()