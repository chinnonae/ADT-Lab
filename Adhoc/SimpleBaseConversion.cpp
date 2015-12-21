#include <iostream>
#include <string>
using namespace std;

int getNum(char c){
    if(c >= '0' && c <= '9')
        return c - '0';
    else{
        return c - 'A' + 10;
    }
}

string getChar(int n){
    string temp;
    if(n < 10){
        temp += '0' + n;
    }else{
        temp +='A' + n - 10;
    }
    return temp;
}


int main(){
    string s;
    cin >> s;
    while(s[0] != '-'){
        string result;
        if(s.size() >= 2 &&s[1] == 'x'){
            int index = 1;
            int num = 0;
            for(int i = s.size()-1; i >= 2; i--){
                num += getNum(s[i]) * index;

                index *= 16;
            }
            cout << num << endl;
        }else{
            int index = 1;
            int num = 0;

            for(int i = s.size()-1; i >= 0; i--){
                num += getNum(s[i]) * index;
                index *= 10;
            }

            while(num > 0){
                result.insert(0, getChar(num%16));
                num /= 16;
            }
            result.insert(0, "0x");
            cout << result << endl;
        }

        cin >> s;
    }
}
