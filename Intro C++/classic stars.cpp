#include <iostream>

using namespace std;

int main(){
    int input;
    cin >> input;

    for(int i = 1 ; i <= input ; i++){
        for(int j = 1; j <= input ; j++){
            if( input - (j+i) < 0 ){
                cout << "*";
            } else {
                cout << " ";
            }

        }
        cout << endl;
    }
}
