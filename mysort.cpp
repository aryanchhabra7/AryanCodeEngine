// Name: Aryan Chhabra
// Class: (CECS 325-01)
// Project Name: (Prog 3 – Sorting Contest)
// Due Date: (10/14/2024)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

// This function performs the bubble sort
void bubble(int A[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (A[j] > A[j + 1]) {
                std::swap(A[j], A[j + 1]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " input-file output-file\n";
        return 1;
    }

    std::ifstream infile(argv[1]);
    std::ofstream outfile(argv[2]);

    if (!infile || !outfile) {
        std::cerr << "[ERROR OPENING FILES]\n";
        return 1;
    }

    std::vector<int> numbers;
    int num;

    // Reads numbers from the file
    while (infile >> num) {
        numbers.push_back(num);
    }

    // Converts vector to an array
    int size = numbers.size();
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = numbers[i];
    }

    // Logs the start of bubble sort
    std::cout << "Starting Array bubble sort with " << size << " items\n";

    // Sorts the array with timing
    auto start = std::chrono::high_resolution_clock::now();
    bubble(arr, size);
    auto end = std::chrono::high_resolution_clock::now();

    // Calculates and displays the elapsed time
    std::chrono::duration<double> duration = end - start;
    std::cout << "Ending bubble sort\n";
    std::cout << "Bubble sort took " << duration.count();

    // Writes the sorted numbers into the output file
    for (int i = 0; i < size; ++i) {
        outfile << arr[i] << "\n";
    }

    delete[] arr;
    infile.close();
    outfile.close();

    return 0;
}
