#include <cstdlib>
#include <iostream>
using namespace std;

template <class Elem> class Astack {
private:
  int maxSize;
  int top;
  Elem *listArray;

public:
  Astack(int size = 10);
  void push(Elem);
  Elem pop();
  Elem peek();
  int size();
  bool isEmpty();
  bool isFull();
};

template <class Elem> Astack<Elem>::Astack(int size) {
  listArray = new Elem[size];
  maxSize = size;
  top = -1;
}

template <class Elem> void Astack<Elem>::push(Elem x) {
  if (isFull()) {
    cout << "Stack is full";
  }
  listArray[++top] = x;
}

template <class Elem> Elem Astack<Elem>::pop() {
  if (isEmpty()) {
    cout << "Stack is empty";
  }
  return listArray[top--];
}

template <class Elem> Elem Astack<Elem>::peek() { return listArray[top]; }

template <class Elem> int Astack<Elem>::size() { return top + 1; }

template <class Elem> bool Astack<Elem>::isEmpty() { return top == -1; }

template <class Elem> bool Astack<Elem>::isFull() { return top == maxSize - 1; }

bool balancedBracket(string str) {
  char c;
  Astack<char> bracket_stack(str.length());

  for (int i = 0; i < str.length(); i++) {
    c = str.at(i);
    if (bracket_stack.isEmpty()) {
      bracket_stack.push(c);
    }

    else if (bracket_stack.peek() == '(' && c == ')' ||
             bracket_stack.peek() == '{' && c == '}' ||
             bracket_stack.peek() == '[' && c == ']') {
      bracket_stack.pop();
    } else
      bracket_stack.push(c);
  }

  if (bracket_stack.isEmpty())
    return true;
  else
    return false;
}

int main() {
  string string1 = "[()]{}{[()()]()}";
  string string2 = "[(])";
  cout << string1 << endl << string2 << endl;

  if (balancedBracket(string1))
    cout << "True" << endl;
  else
    cout << "False" << endl;

  if (balancedBracket(string2))
    cout << "True" << endl;
  else
    cout << "False" << endl;
  return 0;
}
