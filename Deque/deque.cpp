#include <iostream>
#include <queue>
using namespace std;

class Deque
{
  int array[10];
  int front;
  int rear;
  int size;

public:
  Deque(int size) 
  {
    front = -1;
    rear = 0;
    this->size = size;
  }
  void insertfront(int key);
  void insertrear(int key);
  void deletefront();
  void deleterear();
  void showdq();
  int getFront();
  int getRear();
};

void Deque::insertfront(int key)
{
  if (front == -1) 
  {
    front = 0;
    rear = 0;
  }
  else if (front == 0) 
  {
    front = size - 1;
  }
  else 
  {
    front = front - 1;
  } 
  array[front] = key; 
}

void Deque ::insertrear(int key)
{
  if (front == -1)
  {
    front = 0;
    rear = 0;
  }

  else if (rear == size - 1) 
  {
    rear = 0;
  }
  else
  {
    rear = rear + 1;
  } 
  array[rear] = key;
}

void Deque ::deletefront()
{
  if (front == rear)
  {
    front = -1;
    rear = -1;
  }

  else
    if (front == size - 1)
    {
       front = 0;
    }
    else
    {
       front = front + 1;
    }
}

void Deque::deleterear()
{
  if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else if (rear == 0)
  {
    rear = size - 1;
  }  
  else
  {
     rear = rear - 1;
  }
}

void Deque::showdq()
{
  for (int i = 0; i <= 4; i++) {
      cout << array[i] <<  " ";
  }
  cout << endl;
}

int Deque::getFront()
{
  return array[front];
}

int Deque::getRear()
{
  return array[rear];
}

int main()
{
  Deque dq(5);
  int in;

  cout << "Input 5 numbers" << endl;
  
  for (int i = 0; i <= 4; i++)
  {
    cin >> in;
    dq.insertrear(in);
  }

  cout << "Current deque is: " ;
  dq.showdq();
  cout << endl;
  
  cout << "last number in the deque " << dq.getRear() << endl;
  dq.deleterear();
  cout << "new last item after removing old one: " << dq.getRear() << endl;
  cout << "adding 69 to the front" << endl;
  dq.insertfront(69);
  cout << "new front item is " << dq.getFront() << endl;
  dq.deletefront();
  cout << "new front item after removing old one: " << dq.getFront() << endl;
    
  return 0;
}
