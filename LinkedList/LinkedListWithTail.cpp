#include <iostream>

using namespace std;

typedef int valueType;

struct ListNode
{
  valueType val;
  ListNode* next;

  ListNode(valueType val, ListNode* next=0)
    : val(val), next(next) {}
};

class LinkedList
{
private:
  ListNode* header;
  ListNode* tail;
  void free_list();

public:
  LinkedList();
  ~LinkedList();
  void print_list();
  void insert_front(valueType x);
  void append(valueType x);
};

LinkedList::LinkedList()
{
  header = new ListNode(0);
  tail = header;
}

LinkedList::~LinkedList()
{
  free_list();
}

void LinkedList::print_list()
{
  ListNode* node = header->next;
  while(node != 0) {
    cout << node->val << endl;
    node = node->next;
  }
}

void LinkedList::free_list()
{
    ListNode* nextNode = header->next;
    while(nextNode != 0){
        ListNode* temp = nextNode->next;
        delete nextNode;
        nextNode = temp;
    }

}

void LinkedList::append(valueType x)
{
    ListNode* newNode;
    if(tail == header){
        newNode = new ListNode(x);
        header->next = newNode;
        tail = newNode;

    }else{
        ListNode* newNode = new ListNode(x);
        tail->next = newNode;
        tail = newNode;
    }

}

void LinkedList::insert_front(valueType x)
{
    if(tail == header){
        ListNode* newNode = new ListNode(x);
        header->next = newNode;
        tail = newNode;
    }else{
        ListNode* oldNext = header->next;
        header->next = new ListNode(x, oldNext);
    }

}

main()
{
  LinkedList list;
  int t;

  cin >> t;
  for(int i = 0; i < t; i++) {
    int dir, val;
    cin >> dir >> val;
    if(dir == 1) {
      list.insert_front(val);
    } else {
      list.append(val);
    }
  }
  list.print_list();
}
