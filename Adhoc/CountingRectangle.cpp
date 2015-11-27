#include <iostream>
using namespace std;

int countRect(char *line,int index, int size){
    if(index >= size) return 0;
    if(line[index] == '1'){
        return countRect(line, index+1, size);
    }else{
        return countRect(line, index+1, size);
    }
}

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
        char line[n*m];
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                line[count] = rect[i][j];
                count++;
            }
        }
        cout << countRect(line,0,n*m) << endl;
    }while(n != 0 && m != 0);
}


