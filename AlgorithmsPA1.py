# Aryan Chhabra
import csv
import sys

sys.setrecursionlimit(5000)


# Recursive function (function that calls itself) in order to search for linked rows for the passed row

def findlink(row):
    for matchingRow in lines:
        if row[0] != matchingRow[0] and row[1] == matchingRow[0]:
            if len(links) == 0:
                links.append(row[0])
                links.append(row[1])
            links.append(matchingRow[1])
            findlink(matchingRow)
        else:
            continue
    return links


# Function to find the longest list in the two-dimensional list of chained links

def getmaxlistlength(multilistoflinks):
    maxListLength = 0
    for listoflinks in multilistoflinks:
        linklistlength = len(listoflinks)
        if linklistlength > maxListLength:
            maxListLength = linklistlength
    return maxListLength


# Main function logic that reads the CSV file and loops through all its lines to find linked rows

lines = []
with open(sys.argv[1], newline = '') as csvfile:
    csvReader = csv.reader(csvfile, delimiter = ',')
    # Copy all the lines read from the csv file into an array
    for csvRow in csvReader:
        lines.append(csvRow)

linkedLists = []
links = []

# Loop through the array of lines in the csv file to find links and store each list in a two-dimensional list

for line in lines:
    links = findlink(line)
    if len(links) != 0:
        linkedLists.append(links)
        links = []

# Find the maximum length of the list in the (two-dimensional) list of linked lists

biggestListLength = getmaxlistlength(linkedLists)

# Print the lists having the maximum length

for linkedList in linkedLists:
    if len(linkedList) == biggestListLength:
        print(f'{linkedList} with length {len(linkedList)}')