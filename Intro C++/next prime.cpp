#include <iostream>
using namespace std;

bool check_prime(int p){
    if( p <= 1){
        return false;
    }
    if ( p == 2){
        return true;
    }
    else if( p % 2 == 0 ){
        return false;
    }

    int i = 3;

    while( i <= p ){
        if(i != p && p % i == 0){
        return false;
        }
        i = i + 2;
    }
    return true;
}

int main(){
    int p;
    cin >> p;

    if(p <= 1){
        p = 2;
    }else if(p % 2 == 0){
        p++;
    } else {
        p += 2;
    }
    while(!check_prime(p)){
        p += 2;
    }
    cout << p << endl;
}
