#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[10] = {0};

    for(int i = 0; i < n; i++){
        char type;
        int index, highest = 0, range, height;
        cin >> type;
        cin >> index;
        if(type == '-'){
            range = 3;
            height = 1;
        } else if (type == 'o'){
            range = 1;
            height = 2;
        } else if (type == 'i'){
            height = 4;
            range = 0;
        }
        for(int j = index - 1; j < index+range; j++){
            int stack_size = arr[j];
            if(highest < stack_size){
                highest = stack_size;
            }
        }
        for(int j = index-1; j < index+range; j++){
            int stack_size = arr[j];
            arr[j] += highest - arr[j];
            arr[j] += height;
        }
    }
    int maxHeight = 0;
    for(int i = 0; i < 10; i++){
        int k = arr[i];
        if(maxHeight < k){
            maxHeight = k;
        }
    }
    cout << maxHeight << endl;
}
