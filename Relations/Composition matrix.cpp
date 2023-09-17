#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Define the size of the matrices
    int size = 4; // You can change the size as needed

    // Define matrices for the two relations
    vector<vector<int>> matrixR(size, vector<int>(size, 0));
    vector<vector<int>> matrixS(size, vector<int>(size, 0));

    // Populate matrixR (relation R)
    matrixR[0][1] = 1;
    matrixR[1][2] = 1;
    matrixR[2][3] = 1;
    matrixR[3][0] = 1;

    // Populate matrixS (relation S)
    matrixS[0][1] = 1;
    matrixS[1][2] = 1;
    matrixS[2][3] = 1;
    matrixS[3][0] = 1;

    // Print matrixR (relation R)
    cout << "Matrix R (Relation R):" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrixR[i][j] << " ";
        }
        cout << endl;
    }

    // Print matrixS (relation S)
    cout << "\nMatrix S (Relation S):" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrixS[i][j] << " ";
        }
        cout << endl;
    }

    // Initialize the composition matrix
    vector<vector<int>> compositionMatrix(size, vector<int>(size, 0));

    // Multiply matrices R and S to get the composition matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                compositionMatrix[i][j] += matrixR[i][k] * matrixS[k][j];
            }
        }
    }

    // Print the composition matrix
    cout << "\nComposition Matrix:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << compositionMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
