import json



jsonFile = open("Sample-employee-JSON-data.json", "r")

data = json.load(jsonFile)

jsonFile.close()



csvFile = open("Sample-employee-CSV-data.csv", "w")

for i in data["Employees"][0].keys():
    csvFile.write(i)
    if i != "emailAddress":
        csvFile.write(",")
    else:
        csvFile.write("\n")

for i in data["Employees"]:
    for j in i.keys():
        csvFile.write(i[j])
        if j != "emailAddress":
            csvFile.write(",")
        else:
            csvFile.write("\n")

csvFile.close()