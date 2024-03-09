def abbreviation(strInput):
    strOutput = ""

    for i in range(len(strInput)):
        if i == 0:
            strOutput += strInput[i]
        elif strInput[i - 1] == " ":
            strOutput += strInput[i]

    strOutput = strOutput.upper()
    return strOutput



myStr = input("Введите строку: ")
print("Аббревиатура этой строки:", abbreviation(myStr))