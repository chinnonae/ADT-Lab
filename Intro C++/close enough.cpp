#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int n;
    int L;

    cin >> n;
    cin >> L;

    int is[n];
    int count = 0;

    for(int i = 0 ; i < n ; i++){
        cin >> is[i];
    }

    int range;
    for(int i = 0; i < n ; i++){
        for(int j = i+1; j < n; j++){
            range = abs(is[i] - is[j]);
            if(range <= L){
                count++;
            }
        }
    }

    cout << count << endl;

}
