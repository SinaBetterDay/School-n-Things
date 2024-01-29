#include <iostream>
#include <bitset>
#include <sstream>
using namespace std;

int main() {
    string binaryInput;
    cout << "Enter a binary number: ";
    cin >> binaryInput;
    bitset<32> binary(binaryInput);
    stringstream hexStream;
    hexStream << hex << binary.to_ulong();
    string hexadecimal = hexStream.str();
    cout << "Hexadecimal equivalent: " << hexadecimal << endl;
    return 0;
}
