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
