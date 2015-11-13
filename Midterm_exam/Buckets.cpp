#include <iostream>
using namespace std;

int get_bucket(int* buckets){
    int min = buckets[0];
    int minIndex = 0;
    for(int i = 1; i < 5; i++){
        if(min > buckets[i]){
            min = buckets[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main(){
    int buckets[5] = {0};
    int tank = 0;
    int n;
    cin >> n;

    for(n ; n > 0; n--){
        int jar;
        cin >> jar;

        int bucket = get_bucket(buckets);
        buckets[bucket] += jar;
        if(buckets[bucket] >= 1000){
            buckets[bucket] = 0;
            tank += 1000;
        }
    }

    cout << tank << endl;
}
