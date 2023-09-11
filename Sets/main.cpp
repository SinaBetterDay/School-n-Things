#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// Function to display a set
void displaySet(const set<int>& s) {
    cout << "{ ";
    for (int elem : s) {
        cout << elem << " ";
    }
    cout << "}" << endl;
}

// Function to perform union of two sets
set<int> setUnion(const set<int>& s1, const set<int>& s2) {
    set<int> result = s1;
    result.insert(s2.begin(), s2.end());
    return result;
}

// Function to perform intersection of two sets
set<int> setIntersection(const set<int>& s1, const set<int>& s2) {
    set<int> result;
    for (int elem : s1) {
        if (s2.find(elem) != s2.end()) {
            result.insert(elem);
        }
    }
    return result;
}

// Function to perform complement of a set in a given universe set
set<int> setComplement(const set<int>& s, const set<int>& universe) {
    set<int> result;
    for (int elem : universe) {
        if (s.find(elem) == s.end()) {
            result.insert(elem);
        }
    }
    return result;
}

// Function to perform difference of two sets (s1 - s2)
set<int> setDifference(const set<int>& s1, const set<int>& s2) {
    set<int> result = s1;
    for (int elem : s2) {
        result.erase(elem);
    }
    return result;
}

// Function to perform symmetric difference of two sets
set<int> setSymmetricDifference(const set<int>& s1, const set<int>& s2) {
    set<int> result = setUnion(setDifference(s1, s2), setDifference(s2, s1));
    return result;
}

int main() {
    set<int> set1, set2;

    int elem;
    cout << "Enter elements of Set 1 (space-separated, -1 to stop): ";
    while (cin >> elem && elem != -1) {
        set1.insert(elem);
    }

    cout << "Enter elements of Set 2 (space-separated, -1 to stop): ";
    while (cin >> elem && elem != -1) {
        set2.insert(elem);
    }

    int choice;
    do {
        cout << "\nSet Operations Menu:" << endl;
        cout << "1. Union" << endl;
        cout << "2. Intersection" << endl;
        cout << "3. Complement" << endl;
        cout << "4. Difference" << endl;
        cout << "5. Symmetric Difference" << endl;
        cout << "6. Enter New Sets" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Union of Set 1 and Set 2: ";
                displaySet(setUnion(set1, set2));
                break;
            case 2:
                cout << "Intersection of Set 1 and Set 2: ";
                displaySet(setIntersection(set1, set2));
                break;
            case 3:
                cout << "Complement of Set 1: ";
                displaySet(setComplement(set1, set2));
                break;
            case 4:
                cout << "Difference of Set 1 - Set 2: ";
                displaySet(setDifference(set1, set2));
                break;
            case 5:
                cout << "Symmetric Difference of Set 1 and Set 2: ";
                displaySet(setSymmetricDifference(set1, set2));
                break;
            case 6:
                set1.clear();
                set2.clear();
                cout << "Enter elements of Set 1 (space-separated, -1 to stop): ";
                while (cin >> elem && elem != -1) {
                    set1.insert(elem);
                }
                cout << "Enter elements of Set 2 (space-separated, -1 to stop): ";
                while (cin >> elem && elem != -1) {
                    set2.insert(elem);
                }
                break;
            case 7:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 7);

    return 0;
}
