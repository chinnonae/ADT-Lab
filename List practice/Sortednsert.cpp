#include <list>
#include <iostream>

using namespace std;

void sorted_insert(list<int>& li, int x)
{
  list<int>::iterator iter = li.begin();
  while(iter != li.end()){
    int curr = (*iter);
    if(x > curr){
        li.insert(iter,x);
        break;
    }else{
        iter++;
    }
  }
}

main()
{
  list<int> mylist;

  sorted_insert(mylist,10);
  sorted_insert(mylist,1000);
  sorted_insert(mylist,100);
  sorted_insert(mylist,5);
  sorted_insert(mylist,200);
  sorted_insert(mylist,250);
  sorted_insert(mylist,10);

  list<int>::iterator li = mylist.begin();
  while(li != mylist.end()) {
    cout << *li << endl;
    ++li;
  }
}
