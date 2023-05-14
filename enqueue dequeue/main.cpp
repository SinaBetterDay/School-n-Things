#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        
        for (int i = 0; i < size; i++) {
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
    
    void displayStack() {
        if (q.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout << "Original stack: ";
    stack.displayStack();
    
    stack.push(7);

    cout << "Stack after pushing 7: ";
    stack.displayStack();

    cout << "Stack after a pop: ";
    stack.pop();
    stack.displayStack();

    cout << "Stack after a pop: ";
    stack.pop();
    stack.displayStack();
    
    return 0;
}
