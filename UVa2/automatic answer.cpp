#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        int temp = (((num * 63) + 7492) * 5 - 498)/10;
        if(temp < 0) temp *= -1;
        cout << temp%10 << endl;

    }
}
