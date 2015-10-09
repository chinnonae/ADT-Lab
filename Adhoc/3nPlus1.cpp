#include <iostream>

using namespace std;

int findCycle(int i){

    int count = 1;
    while(i != 1){
        if(i % 2 == 1)
            i = 3*i+1;
        else
            i /= 2;
        count += 1;
    }
    return count;
}

int findMaxCycle(int i, int j){
    int maxCount = 0;
    int a, b;
    if(i < j){
        a = i;
        b = j;
    } else {
        a = j;
        b = i;
    }
    for(a ; a <= b ; a++){
        int cycle = findCycle(a);
        if(maxCount < cycle)
            maxCount = cycle;
    }
    return maxCount;
}



int main(){
    while(!cin.eof()){
        int i,j;

        cin >> i;
        if(cin.eof()){

        }
        cin >> j;
        int result = findMaxCycle(i, j);
        cout << i << " " << j << " " << result << endl;
    }
}
