#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int test;
    cin >> test;

    for(int i = 1; i <= test; i++){
        int price = 0;
        int cNO;
        cin >> cNO;
        char chars[cNO];
        int prices[cNO];
        for(int j = 0; j < cNO; j++){
            cin >> chars[j];
            cin >> prices[j];
        }

        int lNO;
        cin >> lNO;
        for(int k = 0; k < lNO; k++){
            string s;
            getline(cin, s);
            cout << s;
            for(int l = 0; l < s.length(); l++){
                char c = s[l];
                int index = 0;
                while(c != chars[index]){
                    index++;
                    if(index >= cNO){
                        break;
                    }
                }
                if(index < cNO){
                    price += prices[index];
                }
            }
        }
        cout << price/100.0 << "$" <<endl;
    }
}
