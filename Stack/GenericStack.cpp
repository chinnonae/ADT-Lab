#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class Stack
{
private:
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

template <typename T>
Stack<T>::Stack()
{
  top_node = 0;
}

template <typename T>
Stack<T>::~Stack()
{
  while(!empty()) {
    pop();
  }
}

template <typename T>
void Stack<T>::push(T value)
{
    if(top_node == 0){
        top_node = new Node(value);
    }else{
        top_node = new Node(value, top_node);
    }

}

template <typename T>
bool Stack<T>::empty()
{
    return top_node == 0;

}

template <typename T>
T Stack<T>::top()
{
    return top_node->value;

}

template <typename T>
T Stack<T>::pop()
{
    T temp = top_node->value;
    Node* oldNode = top_node;
    top_node = top_node->next;
    delete oldNode;
    return temp;

}

main()
{
  int n,t;
  Stack<int> s1;
  Stack<double> s2;

  cin >> t >> n;
  if(t==1) {
    for(int i=0; i<n; i++) {
      int x;
      cin >> x;
      s1.push(x);
    }
    while(!s1.empty()) {
      cout << s1.pop() << endl;
    }
  } else {
    for(int i=0; i<n; i++) {
      double y;
      cin >> y;
      s2.push(y);
    }
    cout << fixed << setprecision(3);
    while(!s2.empty()) {
      cout << s2.pop() << endl;
    }
  }
}
