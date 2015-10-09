#include <iostream>
#include <cstdlib>

using namespace std;

typedef int valueType;

struct ListNode
{
    valueType val;
    ListNode* next;

    ListNode(valueType val, ListNode* next=0)
        : val(val), next(next) {}
    };

void insert_front(ListNode* header, valueType x)
{
    header -> val = x;
    ListNode* tempList = new ListNode(*header);
    header -> next = tempList;
}

void free_list(ListNode*& header)
{
    ListNode* temp;
    while(header != 0) {
        temp = header -> next;
        header = temp;
    }
}

main()
{
  ListNode* first_header = 0;
  for(int i=0; i<5; i++) {
    ListNode* header = new ListNode(0);
    if(!first_header) {
      first_header = header;
    }
    for(int j=0; j<1000; j++) {
      insert_front(header, j);
    }
    free_list(header);
  }
  ListNode* new_header = new ListNode(0);
  int dist = abs(new_header - first_header);
  if(dist < 100) {
    cout << "ok" << endl;
  } else {
    cout << "not ok" << endl;
  }
}
