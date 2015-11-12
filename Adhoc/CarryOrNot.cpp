#include <iostream>
#include <math.h>
using namespace std;

int bitwiseAdd (int i , int j){
    int add[32];
    int a, b;
    if( i < j ){
        a = i;
        b = j;
    } else {
        a = j;
        b = i;
    }
    int index = 0;
    while(a > 0 || b > 0){
        if(a > b){
            if(a % 2 == 1){
                add[index] = 1;
                a = (a-1)/2;
            } else if (a % 2 == 0){
                add[index] = 0;
                a /= 2;
            }
        }else {
            if(a % 2 == b % 2){
                add[index] = 0;
            } else {
                add[index] = 1;
            }
            a /= 2;
            b /= 2;
        }
        index++;
    }
    int result = 0;
    index--;
    for(int i = 0; i <= index ; i++){
        result += pow(2, index - i)*(add[index-i]);
    }

    return result;
}




main()
{
  while(!cin.eof()) {
    int i,j;
8
    cin >> i;
    if(cin.eof()) {
      break;
    }
    cin >> j;
    int result = bitwiseAdd(i,j);
    cout << result << endl;
  }
}
