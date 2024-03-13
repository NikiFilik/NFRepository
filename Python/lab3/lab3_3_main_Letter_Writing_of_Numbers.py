def letterWritingOfNumber(numInput):
    if numInput < 1 or numInput > 9999:
        return "Ошибка ввода: Введите другое число"
    
    numOutput = ""

    if(numInput > 999):
        thousands = numInput // 1000
        if thousands == 1:
            numOutput += "одна тысяча "
        elif thousands == 2:
            numOutput += "две тысячи "
        elif thousands == 3:
            numOutput += "три тысячи "
        elif thousands == 4:
            numOutput += "четыре тысячи "
        elif thousands == 5:
            numOutput += "пять тысяч "
        elif thousands == 6:
            numOutput += "шесть тысяч "
        elif thousands == 7:
            numOutput += "семь тысяч "
        elif thousands == 8:
            numOutput += "восемь тысяч "
        elif thousands == 9:
            numOutput += "девять тысяч "

    if numInput > 99:
        hundreds = (numInput % 1000) // 100
        if hundreds == 1:
            numOutput += "сто "
        elif hundreds == 2:
            numOutput += "двести "
        elif hundreds == 3:
            numOutput += "триста "
        elif hundreds == 4:
            numOutput += "четыреста "
        elif hundreds == 5:
            numOutput += "пятьсот "
        elif hundreds == 6:
            numOutput += "шестьсот "
        elif hundreds == 7:
            numOutput += "семьсот "
        elif hundreds == 8:
            numOutput += "восемьсот "
        elif hundreds == 9:
            numOutput += "девятьсот "
    
    if numInput % 100 > 19:
        tens = (numInput % 100) // 10
        if tens == 2:
            numOutput += "двадцать "
        elif tens == 3:
            numOutput += "тридцать "
        elif tens == 4:
            numOutput += "сорок "
        elif tens == 5:
            numOutput += "пятьдесят "
        elif tens == 6:
            numOutput += "шестьдесят "
        elif tens == 7:
            numOutput += "семьдесят "
        elif tens == 8:
            numOutput += "восемьдесят "
        elif tens == 9:
            numOutput += "девяносто "

        ones = numInput % 10
        if ones == 1:
            numOutput += "один "
        elif ones == 2:
            numOutput += "два "
        elif ones == 3:
            numOutput += "три "
        elif ones == 4:
            numOutput += "четыре "
        elif ones == 5:
            numOutput += "пять "
        elif ones == 6:
            numOutput += "шесть "
        elif ones == 7:
            numOutput += "семь "
        elif ones == 8:
            numOutput += "восемь "
        elif ones == 9:
            numOutput += "девять "                            
    else:
        remainder = numInput % 100
        if remainder == 1:
            numOutput += "один "
        elif remainder == 2:
            numOutput += "два "
        elif remainder == 3:
            numOutput += "три "
        elif remainder == 4:
            numOutput += "четыре "
        elif remainder == 5:
            numOutput += "пять "
        elif remainder == 6:
            numOutput += "шесть "
        elif remainder == 7:
            numOutput += "семь "
        elif remainder == 8:
            numOutput += "восемь "
        elif remainder == 9:
            numOutput += "девять "
        elif remainder == 10:
            numOutput += "десять "
        elif remainder == 11:
            numOutput += "одиннадцать "
        elif remainder == 12:
            numOutput += "двеннадцать "
        elif remainder == 13:
            numOutput += "тренадцать "
        elif remainder == 14:
            numOutput += "четырнадцать "
        elif remainder == 15:
            numOutput += "пятьнадцать "
        elif remainder == 16:
            numOutput += "шестьнадцать "
        elif remainder == 17:
            numOutput += "семьнадцать "
        elif remainder == 18:
            numOutput += "восемьнадцать "
        elif remainder == 19:
            numOutput += "девятьнадцать "
    
    numOutput = numOutput[0].upper() + numOutput[1:]
    return numOutput[:-1]



myNum = int(input("Введите число от 1 до 9999: "))

print("Число буквами:", letterWritingOfNumber(myNum))