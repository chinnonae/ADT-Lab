#include <iostream>
using namespace std;

class Stack
{
private:
  typedef int T;

  struct Node
  {
    T value;
    Node* next;
    Node(T value, Node* next=0)
      : value(value), next(next) {}
  };

  Node* top_node;

public:
  Stack();
  ~Stack();

  void push(T value);
  T top();
  T pop();
  bool empty();
};

Stack::Stack()
{
  top_node = 0;
}

Stack::~Stack()
{
  while(!empty()) {
    pop();
  }
}

void Stack::push(T value)
{
  if(top_node == 0){
    top_node = new Node(value);
  }else{
    top_node = new Node(value, top_node);
  }

}

bool Stack::empty()
{
  return top_node == 0;

}

Stack::T Stack::top()
{
  return top_node->value;

}

Stack::T Stack::pop()
{
  Node* temp = top_node;
  T val = temp->value;
  top_node = top_node->next;
  delete temp;
  return temp->value;

}

main()
{
  int n;
  Stack s;

  cin >> n;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    s.push(x);
  }

  while(!s.empty()) {
    cout << s.pop() << endl;
  }
}
