def strCoder(strInput):
    strOutput = ""

    lastChar = strInput[0]
    charCounter = 1

    for i in strInput[1:]:
        if i == lastChar:
            charCounter +=  1
        else:
            strOutput += lastChar
            if charCounter > 1:
                strOutput += str(charCounter)

            lastChar = i
            charCounter = 1

    strOutput += lastChar
    if charCounter > 1:
        strOutput += str(charCounter)

    return strOutput



def strDecoder(strInput):
    strOutput = ""

    lastChar = strInput[0]
    charCounter = 0

    for i in strInput[1:]:
        if i >= "0" and i <= "9":
            charCounter = charCounter * 10 + int(i)
        else:
            strOutput += lastChar * max(1, charCounter)

            lastChar = i
            charCounter = 0

    strOutput += lastChar * max(1, charCounter)

    return strOutput



myStr = input("Введите строку: ")

print("Закодированная строка:", strCoder(myStr))

#print("Декодированная строка:", strDecoder(myStr))