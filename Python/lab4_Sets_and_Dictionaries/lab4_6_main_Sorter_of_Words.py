text = input("Введите текст: ").split()

textDict = {}

for i in text:
    if i in textDict:
        textDict[i] += 1
    else:
        textDict[i] = 1

textList = [[i, textDict[i]] for i in textDict]
textList.sort(key = lambda word: [-word[1], word[0]])

for i in textList:
    print(i[0])