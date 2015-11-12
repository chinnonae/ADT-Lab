#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    stack<bool> arr[10];
    for(int i = 1; i <= n; i++){
        char type;
        int index;
        cin >> type;
        cin >> index;
        int highest = 0;
        int maxIndex = 0;
        if(type == '-'){
            for(int j = index-1; j < index+3; j++){
                if(highest < arr[j].size()){
                    highest = arr[j].size();;
                    maxIndex = j;
                }
            }
            for(int j = index-1; j< index+3; j++){
                while(arr[j].size() < highest){
                    arr[j].push(false);
                }
                arr[j].push(true);
            }
        } else if (type == 'o'){
            for(int j = index-1; j < index+1; j++){
                if(highest < arr[j].size()){
                    highest = arr[j].size();;
                    maxIndex = j;
                }
            }
            for(int j = index-1; j < index+1; j++){
                while(arr[j].size() < highest){
                    arr[j].push(false);
                }
                arr[j].push(true);
                arr[j].push(true);
            }
        } else if (type == 'i'){
            for(int j = 0; j < 4; j++){
                arr[index-1].push(true);
            }
        }
    }
    int maxHeight = 0;
    for(int i = 0; i < 10; i++){
        if(arr[i].size() > maxHeight){
            maxHeight = arr[i].size();
        }
    }
    cout << maxHeight;
}
