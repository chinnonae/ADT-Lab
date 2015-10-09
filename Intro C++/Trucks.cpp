#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;


    int weightOnCurrent = 0;
    int weight;
    int truck = 0;


    for(int i = 0 ; i < n ; i++){
        cin >> weight;

        int addedWeight = weightOnCurrent + weight;
        if(addedWeight <= 1000 & i != n-1){
            weightOnCurrent += weight;
        } else if( i != n-1){
            weightOnCurrent = weight;
            truck++;
        } else {
            if(addedWeight <= 1000){
                truck++;
            } else {
                truck += 2;
            }
        }
    }
    cout << truck << endl;
}
