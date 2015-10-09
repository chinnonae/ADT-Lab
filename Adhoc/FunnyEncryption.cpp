#include <iostream>
using namespace std;


int decimalEncrypt(int m){
    int count = 0;
    while( m > 0){
        if(m % 2 == 1){
            count += 1;
            m = (m-1)/2;
        } else {
            m /= 2;
        }
    }
    return count;

}

int hexaEncrypt(int m){
    int count = 0;
    while( m > 0 ){
        count += decimalEncrypt( m % 10);
        m /= 10;
    }
    return count;
}

void encrypt(int m){
    int dec = decimalEncrypt(m);
    int hex = hexaEncrypt(m);
    cout << dec << " " <<  hex << endl;
}



int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int m;
        cin >> m;
        encrypt(m);
    }


}
