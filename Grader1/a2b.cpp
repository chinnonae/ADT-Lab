#include <iostream>
using namespace std;

main(){
    int a, b;
    cin >> a;
    cin >> b;
    int result = 0;
    for(a; a <=b ; a++){
        result += a;
    }
    cout << result << endl;
}
