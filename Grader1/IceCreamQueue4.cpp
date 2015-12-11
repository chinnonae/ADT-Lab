#include <iostream>
using namespace std;
template <typename T>
class Heap
{
private:
  T* data;
  int count;

public:
  Heap(int max_size);
  ~Heap();

  int size() { return count; }
  void insert(T x);
  T get_min();
  T extract_min();

private:
  void percolate_up(int i);
  void percolate_down(int i);
  int parent_id(int i) { return (i-1)/2; }
  int left_child_id(int i) { return i*2+1; }
  int right_child_id(int i) { return i*2+2; }
};

template <typename T>
Heap<T>::Heap(int max_size)
{
  data = new T[max_size];
  count = 0;
}

template <typename T>
Heap<T>::~Heap()
{
  delete [] data;
}

template <typename T>
void Heap<T>::insert(T x)
{
  data[count] = x;
  count++;
  percolate_up(count-1);
}

template <typename T>
T Heap<T>::get_min()
{
  return data[0];
}

template <typename T>
T Heap<T>::extract_min()
{
  T m = data[0];
  data[0] = data[count-1];
  count--;
  percolate_down(0);
  return m;
}

template <typename T>
void Heap<T>::percolate_up(int i)
{
  if(i == 0) return;
  int parentId = parent_id(i);
  if(data[parentId] > data[i]){
    T temp = data[parentId];
    data[parentId] = data[i];
    data[i] = temp;
    percolate_up(parentId);
  }
}

template <typename T>
void Heap<T>::percolate_down(int i)
{

  int leftC = left_child_id(i);
  int rightC = right_child_id(i);
  if(leftC > count && rightC > count) return;
  if(leftC > count) leftC = rightC;
  if(rightC > count) rightC = leftC;
  if(data[i] > data[leftC] || data[i] > data[rightC]){
    if(data[leftC] <= data[rightC]){
        swap(data[i],data[leftC]);
        percolate_down(leftC);
    }else if(data[rightC] <= data[leftC]){
        swap(data[i],data[rightC]);
        percolate_down(rightC);
    }
  }

}

int main(){
    Heap<pair <pair<int,int> ,int> > heap(100000);

    int m;
    cin >> m;
    int q = 0;
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        if( t == 1 ){
            int n;
            cin >> n;
            for(int j = 0; j < n; j++){
                int id, age;
                cin >> id;
                cin >> age;
                pair < pair< int, int> , int> temp = make_pair(make_pair(age,q++),id);
                heap.insert(temp);
            }
        }
        if(t == 2){
            pair<pair<int,int>,int> cus = heap.extract_min();
            cout << cus.second << endl;

        }
    }
}
