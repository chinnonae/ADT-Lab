#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    set<int> ns;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        ns.insert(temp);
    }

    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        set<int>::iterator lwiter = ns.lower_bound(temp);
        set<int>::iterator upiter = ns.upper_bound(temp);
        int lower ;
        if(lwiter != ns.begin()){
            if(*lwiter == temp){
                lower = *lwiter;
            }else{
                lower = *--lwiter;
            }
        }else{ lower = 0;}
        int upper;
        if(upiter == ns.end()){
            upper = 0;
        }else{
            upper = *upiter;
        }

        cout << "-" << lower << endl;
        cout << "-" << upper << endl;

        if(lower == 0){
            cout << upper << endl;
        }else if(upper == 0){
            cout << lower << endl;
        }else if(abs(temp - lower) > abs(temp - upper)){
            cout << upper << endl;
        }else{
            cout << lower << endl;
        }
    }

    for(set<int>::iterator iter = ns.begin(); iter != ns.end(); iter++){
        cout << "---" << *iter << endl;
    }


}
