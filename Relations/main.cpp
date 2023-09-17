#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    // Define sets A and B
    set<int> A = {1, 2, 3, 4};
    set<char> B = {'a', 'b', 'c'};

    // Define relation R as a map of pairs
    map<int, char> R = {{1, 'a'}, {2, 'c'}, {3, 'b'}};

    // Create a matrix to represent the relation
    vector<vector<int>> matrix(A.size(), vector<int>(B.size(), 0));

    // Populate the matrix based on relation R
    for (const auto &pair : R) {
        int x = pair.first;
        char y = pair.second;

        auto it_x = A.find(x);
        auto it_y = B.find(y);

        if (it_x != A.end() && it_y != B.end()) {
            int rowIndex = distance(A.begin(), it_x);
            int colIndex = distance(B.begin(), it_y);
            matrix[rowIndex][colIndex] = 1;
        }
    }

    // Print the matrix
    cout << "  ";
    for (char element : B) {
        cout << element << " ";
    }
    cout << endl;

    for (int elem : A) {
        cout << elem << " ";
        int rowIndex = distance(A.begin(), A.find(elem));
        for (int j = 0; j < B.size(); j++) {
            cout << matrix[rowIndex][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
