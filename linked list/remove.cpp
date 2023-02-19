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
  virtual T remove() = 0;
};

int main() {
  list<int> my_list = {2, 23, 15, 5, 9};
  
  for (int x : my_list) {
    cout << x << endl;
  }

  my_list.remove(15);
  cout << endl << "removing 15..." << endl;
  
  for (int x : my_list) {
    cout << x << endl;
  }
}
