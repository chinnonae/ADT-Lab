#include <iostream>
using namespace std;

int main(){
    int n;
    int schedule[31] = {0};
    int count = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        bool reject = false;
        int a, b, h;
        cin >> a >> b >> h;
        for(int j = a; j <= b; j++){
            if(schedule[j] + h > 6){
                reject = true;
                for(j -= 1 ; j >= a; j--){
                    schedule[j] -= h;
                }
                break;
            }else{
                schedule[j] += h;
            }
        }
        if(!reject){count += 1;}
    }

    cout << count << endl;
}
