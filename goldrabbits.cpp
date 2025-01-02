
#include <iostream>
#include <fstream>
#include <limits>

int main() {
    std::ofstream outfile("goldrabbits.log");
    
    if (!outfile) {
        std::cerr << "Error creating log file." << std::endl;
        return 1;
    }

    long long prev = 1, curr = 1;
    int index = 0;

    outfile << index << ": GoldRabbits(" << index << ") = " << prev << " fiboCount:" << std::endl;
    index++;
    outfile << index << ": GoldRabbits(" << index << ") = " << curr << " fiboCount:" << std::endl;

    long long next;
    index++;
    while (true) {
        next = prev + curr;
        
        // Check for overflow by verifying if next would be negative or exceed long long limit
        if (next < 0 || next > std::numeric_limits<long long>::max()) {
            outfile << index << ": GoldRabbits(" << index << ") = Overflow at fibo(" << index << ")" << std::endl;
            break;
        }
        
        outfile << index << ": GoldRabbits(" << index << ") = " << next << " fiboCount:" << std::endl;
        
        // Update previous two Fibonacci numbers
        prev = curr;
        curr = next;
        index++;
    }
    
    outfile.close();
    return 0;
}
