#include <iostream>

using namespace std;

int main(){

    int numer;
    int denom;
    cin >> numer;
    cin >> denom;

    int max;
    if(numer > denom){
        max = numer;
    } else {
        max = denom;
    }
    int GCD;
    for(int i = 2; i <= max; i++){
        if(numer % i == 0 && denom % i == 0){
            GCD = i;
        }
    }
    cout << numer/GCD;
    cout << "/";
    cout << denom/GCD << endl;
}
