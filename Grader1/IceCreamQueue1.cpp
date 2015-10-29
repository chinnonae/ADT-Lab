#include <iostream>
#include <string>
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
  valueType dequeue();
  int count;
};

LinkedList::LinkedList()
{
  header = new ListNode(0);
  tail = header;
  count = 0;
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
    count = 0;

}

void LinkedList::append(valueType x)
{
    ListNode* newNode;
    count += 1;
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

valueType LinkedList::dequeue(){
    if(header->next==0)return -1;
    count -= 1;
    ListNode* next = header->next;
    valueType temp = next->val;
    header->next = next->next;
    if(next->next == 0)tail = header;
    return temp;
}


int main(){
    LinkedList lst;
    int m;
    cin >> m;
    for(int i = 0 ; i < m; i++){
        int t;
        cin >> t;
        if(t == 1){
            int n;
            cin >> n;
            for(int j = 0; j < n; j++){
                int id;
                cin >> id;
                lst.append(id);
            }
        }
        if(t == 2){
            int id = lst.dequeue();
            if(id != -1) cout << id << endl;
        }
    }
    cout << lst.count << endl;
}
