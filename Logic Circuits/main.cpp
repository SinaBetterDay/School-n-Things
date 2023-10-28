#include <iostream>
using namespace std;

int main() {
  cout << "| Panel 1 | Panel 2 | Panel 3 | System Enabled |\n";
  cout << "------------------------------------------------\n";

  for (int panel1 = 0; panel1 <= 1; panel1++) {
    for (int panel2 = 0; panel2 <= 1; panel2++) {
      for (int panel3 = 0; panel3 <= 1; panel3++) {
        // Calculate the system state using bitwise operations
        int systemEnabled =
            (panel1 & panel2) | (panel1 & panel3) | (panel2 & panel3);

        cout << "|    " << panel1 << "    |    " << panel2 << "    |    " << panel3 << "    |       " << systemEnabled << "        |\n";
      }
    }
  }
  return 0;
}
