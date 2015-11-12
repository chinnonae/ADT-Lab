#include <iostream>
using namespace std;

int main(){
    int n,m;
    do{
        cin >> n;
        if(n==0) break;
        cin >> m;
        if(m==0) break;
        string rect[n];
        for(int i = 0; i < n; i++){
            cin >> rect[i];
        }
        cout << countRect(rect) << endl;
    }while(n != 0 && m != 0)
}

int countRect(string &rect){

}
