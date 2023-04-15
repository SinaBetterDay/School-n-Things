#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

double calcAverage(const vector<double>& scores);

int main() {
    int numScores;
    vector<double> scores;
    cout << "Enter the number of test scores: ";
    cin >> numScores;
    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter test score #" << i+1 << ": ";
        cin >> score;
        while (score < 0) {
            cout << "Test score cannot be negative. Please enter a non-negative value: ";
            cin >> score;
        }
        scores.push_back(score);
    }
    sort(scores.begin(), scores.end());
    double average = calcAverage(scores);
    cout << endl << "Sorted list of test scores:" << endl;
    for (const auto& score : scores) {
        cout << score << endl;
    }
    cout << "Average score: " << fixed << setprecision(2) << average << endl;
    return 0;
}

double calcAverage(const vector<double>& scores) {
    double sum = 0.0;
    for (const auto& score : scores) {
        sum += score;
    }
    return sum / scores.size();
}
