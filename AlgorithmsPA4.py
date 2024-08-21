# Aryan Chhabra

import csv
import sys

def countIntegers(input_filename, output_filename):

    integer_count = {}

    with open(input_filename, 'r') as infile:
        reader = csv.reader(infile)
        for row in reader:
            if row:
                number = int(row[0])
                if number in integer_count:
                    integer_count[number] += 1
                else:
                    integer_count[number] = 1

    filtered_count = {k: v for k, v in integer_count.items() if v > 1}

    # Sort integers by count in descending order
    sortedCount = sorted(filtered_count.items(), key = lambda x: x[1], reverse = True)

    with open(output_filename, 'w', newline = '') as outfile:
        writer = csv.writer(outfile)
        for number, count in sortedCount:
            writer.writerow([number, count])

def main():
    if len(sys.argv) != 3:
        print("Usage: python pa4.py input_filename output_filename")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    countIntegers(input_file, output_file)


main()
