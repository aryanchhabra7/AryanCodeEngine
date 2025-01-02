// Name: Aryan Chhabra
// Class: (CECS 325-01)
// Project Name: (Prog 3 – Sorting Contest)
// Due Date: (10/14/2024)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[]) {
    // Checks if the program received exactly 3 command-line arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " COUNT MIN MAX\n";
        return 1;
    }

    int count = std::stoi(argv[1]);
    int min = std::stoi(argv[2]);
    int max = std::stoi(argv[3]);

    // Opens the output file "numbers.dat" to store the random numbers
    std::ofstream outfile("numbers.dat");
    if (!outfile) {
        std::cerr << "[ERROR OPENING FILE]\n";
        return 1;
    }

    std::srand(std::time(0));

    // Generates 'count' random numbers between 'min' and 'max' values
    for (int i = 0; i < count; i++) {
        int num = min + std::rand() % (max - min + 1);
        outfile << num << "\n";
    }

    outfile.close();
    return 0;
}