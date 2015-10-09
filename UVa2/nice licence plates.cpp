#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string plate;
        cin >> plate;
        int left = 0;
        int right = 0;
        for(int j = 0; j < 8; j++){
            if(j < 3){
                left += (plate[j] - 'A') * pow(26,2-j);
            } else if (j > 3){
                right += (plate[j] - '0') * pow(10,7-j);
            }
        }
        if( left - right <= 100 && left - right >= -100){
            cout << "nice" << endl;
        } else {
            cout << "not nice" << endl;
        }
    }
}
