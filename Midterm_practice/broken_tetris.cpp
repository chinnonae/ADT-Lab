#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n ;
    cin >> n;
    stack<bool> arr[10];
    for(int i = 1; i <= n; i++){
        char type;
        int index, highest = 0, range, height;
        cin >> type;
        cin >> index;

        if(type == '-'){
            range = 3;
            height = 1;
        }else if(type == 'o'){
            range = 1;
            height = 2;
        }else if(type == 'i'){
            height = 4;
            range = 0;
        }
        for(int j = index-1; j < index+range; j++){
            int stack_size = arr[j].size();
            if(highest < stack_size){
                highest = stack_size;
            }
        }
        for(int j = index-1; j < index+range; j++){
            int stack_size = arr[j].size();
            while(highest > stack_size){
                arr[j].push(false);
                stack_size = arr[j].size();
            }
            for(int k = 0; k < height; k++){
                arr[j].push(true);
            }
        }
    }
    int maxHeight = 0;
    for(int i = 0; i < 10; i++){
        int stack_size = arr[i].size();
        if(maxHeight < stack_size){
            maxHeight = stack_size;
        }
    }
    cout << maxHeight << endl;
}
