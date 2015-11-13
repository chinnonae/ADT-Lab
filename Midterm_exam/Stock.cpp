#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n;
    cin >> k;

    int oldPrice = 0;
    bool hasStock = false;
    int profit = 0;
    int buyAt = 0;
    for(int i = 0; i < n; i++){
        int currPrice;

        cin >> currPrice;
        if(i == 0){
            oldPrice = currPrice;
            continue;
        }
        if(currPrice - oldPrice >= k && !hasStock){
            hasStock = true;
            buyAt = currPrice;
        }else if(currPrice - oldPrice <= -k && hasStock){
            hasStock = false;
            profit += currPrice - buyAt;
        }
        oldPrice = currPrice;
    }

    cout << profit << endl;
}
