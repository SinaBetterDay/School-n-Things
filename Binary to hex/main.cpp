#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string binaryToHex(const string &binary) {
    string hex;
    if (binary.empty()) {
        return hex;
    }


    for (int i = 0; i < binary.size(); i += 4) {
        bitset<4> bits(binary.substr(i, 4));
        hex += static_cast<char>(bits.to_ulong() + (bits.to_ulong() < 10 ? '0' : 'A' - 10));
    }

    return hex;
}

int main() {
    string binaryInput;
    cout << "Enter a binary number: ";
    cin >> binaryInput;

    string hexadecimalOutput = binaryToHex(binaryInput);
    cout << "Hexadecimal representation: " << hexadecimalOutput << endl;

    return 0;
}
