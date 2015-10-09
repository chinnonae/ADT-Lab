#include <iostream>
using namespace std;

template <typename T>
class Counter{
private:
    T counter;
public:
    Counter();
    void inc(T amt);
    T val();
};

template<typename T>
Counter<T>::Counter() { counter = 0; }

template<typename T>
void Counter<T>::inc(T amt) { counter += amt; }

template<typename T>
T Counter<T>::val() { return counter; }

main(){
    Counter<double> c;
    cout << c.val() << endl;
    c.inc(1.2); cout << c.val() << endl;
    c.inc(5.4); cout << c.val() << endl;
    c.inc(100.001); cout << c.val() << endl;
}
