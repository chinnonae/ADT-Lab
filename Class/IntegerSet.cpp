#include <iostream>
using namespace std;
class IntegerSet{
    private:
        static const int max_size = 100;
        int elements[max_size];
        int num_elements;

    public:
        IntegerSet(): num_elements(0){}
        bool is_empty(){ return num_elements == 0; }
        void add(int x);
        void remove(int x);
        bool contains(int x) const;
        void clear();
        IntegerSet set_union(const IntegerSet& o);
        IntegerSet set_difference(const IntegerSet& o);
};

bool IntegerSet::contains(int x)const{
    for(int i = 0; i < num_elements; i++){
        if(elements[i] == x){
            return true;
        }
    }
    return false;
}

void IntegerSet::add(int x){
    if(!contains(x)){
        if(num_elements < max_size){
            elements[num_elements] = x;
            num_elements++;
        } else {
            throw "Too many items";
        }
    }
}

void IntegerSet::remove(int x){
    int index = -1  ;
    bool isFound;
    do{
        index++;
        isFound = elements[index]==x;

    }while((!isFound)&&index<num_elements);

    if(index < num_elements){
        for(int i = index; i < num_elements-1; i++){
            elements[i] = elements[i+1];
        }
        num_elements -= 1;
    }
}

IntegerSet IntegerSet::set_union(const IntegerSet& o){
    IntegerSet out;
    for(int i = 0; i < num_elements; i++){
        out.add(elements[i]);
    }
    for(int i = 0; i < o.num_elements; i++){
        out.add(o.elements[i]);
    }
    return out;
}

IntegerSet IntegerSet::set_difference(const IntegerSet& o){
    IntegerSet out;
//    for(int i = 0; i < o.num_elements; i++){
//        if(!contains(o.elements[i])){
//            out.add(o.elements[i]);
//        }
//    }
    for(int i = 0; i < num_elements; i++){
        if(!o.contains(elements[i])){
            out.add(elements[i]);
        }
    }
    return out;
}


int main(){

  IntegerSet s1,s2;
  s1.add(1);  s1.add(5);  s1.add(10);  s1.add(15);  s1.add(100);
  s2.add(2);  s2.add(5);  s2.add(15);  s2.add(50);  s2.add(90);
  IntegerSet q;
  q = s1.set_union(s2);
  cout << q.contains(1) << q.contains(2) << q.contains(5) << q.contains(15)
       << q.contains(50) << q.contains(100) << q.contains(200) << endl;
  q = s1.set_difference(s2);
  cout << q.contains(1) << q.contains(2) << q.contains(5) << q.contains(15)
       << q.contains(50) << q.contains(100) << q.contains(200) << endl;

}
