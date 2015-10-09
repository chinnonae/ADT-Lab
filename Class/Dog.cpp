#include <iostream>

using namespace std;
class Dog{
    private :
        string name;
        int age;
        float speed;

    public :
        void set_name(string n){
            name = n;
        }
        void set_age(int a) {
            age = a;
        }
        string get_name(){
            return name;
        }
        int get_age(){
            return age;
        }
};

main(){
    Dog d1,d2;
    d1.set_name("someone");
    d1.set_age(100);
    cout << d1.get_name() << d1.get_age() << endl;
}
