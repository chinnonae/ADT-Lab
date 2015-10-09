#include <iostream>
using namespace std;

int getNumber(char c){
    switch(c){
    case 'A': case 'B': case 'C':
        return 2;
    case 'D': case 'E': case 'F':
        return 3;
    case 'G': case 'H': case 'I':
        return 4;
    case 'J': case 'K': case 'L':
        return 5;
    case 'M': case 'N': case 'O':
        return 6;
    case 'P': case 'Q': case 'R': case 'S':
        return 7;
    case 'T': case 'U': case 'V':
        return 8;
    case 'W': case 'X': case 'Y': case 'Z':
        return 9;
    default:
        return 0;
    }
}
int main(){

    while(!cin.eof()){
        char c;
        if(cin.eof()){
            return 0;
        }
        cin >> c;
        if(c == '1' || c == '-' || c == '0'){
            cout << c;
        } else {
            int temp = getNumber(c);
            if (temp == 0)break;
            cout << temp;
        }
    }

}
