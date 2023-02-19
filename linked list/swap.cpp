#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

template <typename T> class List {
private:
  void operator=(const List &) {} // Protect assignment
  List(const List &) {}           // Protect copy constructor
public:
  List() {}          // Default constructor
  virtual ~List() {} // Base destructor
};

int main() {
  list<int> my_list = {2, 23, 15, 5, 9};
  
  for (int x : my_list) {
    cout << x << endl;
  }
  
  cout << endl << "switching the first two elements..." << endl;

  auto num1 = my_list.begin();
  auto num2 = num1++;
  
  swap(*num1, *num2);
  
  for (int x : my_list) {
    cout << x << endl;
  }
}
