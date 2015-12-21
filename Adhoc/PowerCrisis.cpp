#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n != 0){
        bool isTrue = false;
        bool cities[n];
        int m = 1;
        int k = 0;
        while(!isTrue){

            if(n == 13){
                isTrue = true;
                break;
            }
            if(m == 6 || m == 12){
                m++;
                continue;
            }
            m = 5;
            for(int i = 0; i < n; i++){
                if(i == n-1 && k%n == 12){
                    cout << i << "  " << k << endl;
                    isTrue = true;
                    break;
                }
                int count = 0;
                int blackout = 0;
                for(int j = 0; j < n; j++){
                    if(cities[j]) blackout += 1;
                }
                if(blackout == n){
                    continue;
                }
                while(count < m){
                    if(!cities[k%n])count++;
                    k++;

                }

            }
            if(isTrue){
                cout << m << endl;
            }else{
                m++;
            }
        }

        cin >> n;
    }
}
