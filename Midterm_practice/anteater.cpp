#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool skip = false;
    int total = 0;
    for(int i = 0 ; i < n; i++){
        int food;
        cin >> food;
        if(skip) {skip = false; continue;}
        if(food >= 1000){ total += 1000; skip = true;}
        else total += food;
    }
    cout << total;

}
