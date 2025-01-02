# Name: Aryan Chhabra
# Class: (CECS 325-01)
# Project Name: (Prog 3 – Sorting Contest)
# Due Date: (10/14/2024)
#
# I certify that this program is my own original work. I did not copy any part of this program from
# any other source. I further certify that I typed each and every line of code in this program.

# !/bin/bash
# This shell script tests the sorting programs generate.cpp and mysort.cpp

# Removes the previous log file
rm sortrace.log

echo "Generating 1,000,000 random numbers..."
sleep 1
./generate 1000000 -100000 100000
sleep 1

# Runs the system sort and logs the runtime
echo "Starting system sort..." >> sortrace.log
sleep 1
{ time sort -n numbers.dat > systemsort.out; } 2>> sortrace.log

# Runs the custom bubble sort and logs the runtime with additional output
echo "Starting my sort..." >> sortrace.log
sleep 1
{ ./mysort numbers.dat mysort.out; } >> sortrace.log 2>&1

# Checks if the custom sort is correct
sort -c -n mysort.out >> sortrace.log 2>&1

# Logs the overall results
wc mysort.out >> sortrace.log
sort -c -n mysort.out >> sortrace.log
