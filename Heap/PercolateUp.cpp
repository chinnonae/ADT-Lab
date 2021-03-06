#include <iostream>

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
    int temp = data[parentId];
    data[parentId] = data[i];
    data[i] = temp;
    percolate_up(parentId);
  }
}

main()
{
  Heap<int> heap(1000);

  int n;
  std::cin >> n;
  for(int i=0; i<n; i++) {
    int t,x;

    std::cin >> t;
    if(t==0) {
      std::cout << heap.extract_min() << std::endl;
    } else {
      std::cin >> x;
      heap.insert(x);
    }
  }
}
