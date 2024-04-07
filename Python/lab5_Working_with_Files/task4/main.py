import json
import csv


jsonFile = open("Sample-employee-JSON-data.json", "r")
data = json.load(jsonFile)
jsonFile.close()


csvFile = open("Sample-employee-CSV-data.csv", "w", newline = "")
writer = csv.DictWriter(csvFile, data["Employees"][0].keys())
writer.writeheader()
writer.writerows(data["Employees"])
csvFile.close()