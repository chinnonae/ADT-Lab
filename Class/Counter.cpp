#include <iostream>
using namespace std;
class Counter{
    private:
        int c;
    public:
        Counter();
        void inc(); void dec(); void reset();
        int get_value();
};

Counter:: Counter()
    : c(0){}
void Counter::inc() { c++; }
void Counter::dec() { c--; }
void Counter::reset() { c = 0; }
int Counter::get_value() { return c; }

main(){
    Counter c1;

    c1.inc();
    cout << c1.get_value() << endl;
    c1.reset();
    cout << c1.get_value() << endl;
    c1.dec();
    cout << c1.get_value() << endl;
}
