#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
  double fractionDifference;
  double num1, num2, den1, den2;

  cout << "enter a number and its denominator twice \n";
  cin >> num1 >> den1 >> num2 >> den2;

  fractionDifference = ((num1 / den1) - (num2 / den2));
  
  cout << fixed << setprecision(2) << fractionDifference << endl;
  
  return 0;
}
