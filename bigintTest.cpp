// Name: Aryan Chhabra
// Class: (CECS 325-01)
// Project Name: (Prog 6 – Big Integer)
// Due Date: (12/11/2024)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <climits>

using namespace std;

class BigInt {
private:
    vector<char> v; // Stores digits as characters

public:
    // These are the constructors
    BigInt(string str) {
        for (auto it = str.rbegin(); it != str.rend(); ++it)
            v.push_back(*it - '0');
    }

    BigInt(int num) {
        if (num == 0) {
            v.push_back(0);
        } else {
            while (num > 0) {
                v.push_back(num % 10);
                num /= 10;
            }
        }
    }

    BigInt() { v.push_back(0); }

    // All the overloaded operators
    BigInt operator+(const BigInt &rhs) {
        BigInt result;
        result.v.clear();

        int carry = 0, sum = 0;
        size_t maxSize = max(v.size(), rhs.v.size());

        for (size_t i = 0; i < maxSize || carry; ++i) {
            sum = carry;
            if (i < v.size()) sum += v[i];
            if (i < rhs.v.size()) sum += rhs.v[i];
            result.v.push_back(sum % 10);
            carry = sum / 10;
        }

        return result;
    }

    BigInt operator*(const BigInt &rhs) {
        BigInt result;
        result.v.resize(v.size() + rhs.v.size(), 0);

        for (size_t i = 0; i < v.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < rhs.v.size() || carry; ++j) {
                int product = result.v[i + j] + v[i] * (j < rhs.v.size() ? rhs.v[j] : 0) + carry;
                result.v[i + j] = product % 10;
                carry = product / 10;
            }
        }

        while (result.v.size() > 1 && result.v.back() == 0)
            result.v.pop_back();

        return result;
    }

    BigInt operator-(const BigInt &rhs) const {
        BigInt result;
        result.v.clear();

        int carry = 0;
        for (size_t i = 0; i < v.size(); ++i) {
            int sub = v[i] - (i < rhs.v.size() ? rhs.v[i] : 0) - carry;
            if (sub < 0) {
                sub += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            result.v.push_back(sub);
        }

        // Removes the leading zeros
        while (result.v.size() > 1 && result.v.back() == 0)
            result.v.pop_back();

        return result;
    }

    bool operator>=(const BigInt &rhs) const {
        if (v.size() != rhs.v.size())
            return v.size() > rhs.v.size();

        for (auto it1 = v.rbegin(), it2 = rhs.v.rbegin(); it1 != v.rend(); ++it1, ++it2) {
            if (*it1 != *it2)
                return *it1 > *it2;
        }

        return true; // If all digits are equal, the numbers are equal
    }

    bool operator==(const BigInt &rhs) const {
        return v == rhs.v;
    }

    BigInt operator++() { // The prefix increment
        *this = *this + BigInt(1);
        return *this;
    }

    BigInt operator++(int) { // The postfix increment
        BigInt temp = *this;
        *this = *this + BigInt(1);
        return temp;
    }

    BigInt operator/(const BigInt &rhs) {
        BigInt result, current;

        for (auto it = v.rbegin(); it != v.rend(); ++it) {
            current.v.insert(current.v.begin(), *it);
            while (current.v.size() > 1 && current.v.back() == 0)
                current.v.pop_back();

            int count = 0;
            while (current >= rhs) {
                current = current - rhs;
                ++count;
            }
            result.v.insert(result.v.begin(), count);
        }

        while (result.v.size() > 1 && result.v.back() == 0)
            result.v.pop_back();

        return result;
    }

    BigInt operator%(const BigInt &rhs) {
        BigInt current;

        for (auto it = v.rbegin(); it != v.rend(); ++it) {
            current.v.insert(current.v.begin(), *it);
            while (current.v.size() > 1 && current.v.back() == 0)
                current.v.pop_back();

            while (current >= rhs) {
                current = current - rhs;
            }
        }

        return current;
    }

    BigInt fibo() {
        throw runtime_error("Fibonacci function not implemented.");
    }

    BigInt fact() {
        throw runtime_error("Factorial function not implemented.");
    }

    void print() const {
        for (auto it = v.rbegin(); it != v.rend(); ++it)
            cout << char(*it + '0');
    }

    friend ostream &operator<<(ostream &out, const BigInt &num) {
        if (num.v.size() <= 12) {
            for (auto it = num.v.rbegin(); it != num.v.rend(); ++it)
                out << char(*it + '0');
        } else {
            out << num.v.back() << ".";
            for (size_t i = 1; i < 7 && i < num.v.size(); ++i)
                out << char(num.v[num.v.size() - i - 1] + '0');
            out << "e" << num.v.size() - 1;
        }
        return out;
    }
};

void testUnit() {
    int space = 10;
    cout << "\a\nTestUnit:\n" << flush;
    system("whoami");
    system("date");

    // Initializes the variables
    BigInt n1(25);
    BigInt s1("25");
    BigInt n2(1234);
    BigInt s2("1234");
    BigInt n3(n2);
    BigInt fibo(12345);
    BigInt fact(50);
    BigInt imax = INT_MAX;
    BigInt big("9223372036854775807");

    // Displays the variables
    cout << "n1(int)    :" << setw(space) << n1 << endl;
    cout << "s1(str)    :" << setw(space) << s1 << endl;
    cout << "n2(int)    :" << setw(space) << n2 << endl;
    cout << "s2(str)    :" << setw(space) << s2 << endl;
    cout << "n3(n2)     :" << setw(space) << n3 << endl;
    cout << "fibo(12345):" << setw(space) << fibo << endl;
    cout << "fact(50)   :" << setw(space) << fact << endl;
    cout << "imax       :" << setw(space) << imax << endl;
    cout << "big        :" << setw(space) << big << endl;
    cout << "big.print(): "; big.print(); cout << endl;

    cout << n2 << "/" << n1 << " = " << n2 / n1 << " rem " << n2 % n1 << endl;
    cout << "10 + n1 = " << BigInt(10) + n1 << endl;
    cout << "n1 + 10 = " << n1 + BigInt(10) << endl;

    cout << "(n1 == s1)? --> " << ((n1 == s1) ? "true" : "false") << endl;
    cout << "n1++ = ?  --> before:" << n1++ << " after:" << n1 << endl;
    cout << "++s1 = ?  --> before:" << ++s1 << " after:" << s1 << endl;

    cout << "s2 * big = ? --> "<< s2 * big<<endl;
    cout << "big * s2 = ? --> "<< big * s2<<endl;
}

int main() {
    testUnit();
    return 0;
}
