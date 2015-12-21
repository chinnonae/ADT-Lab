#include <iostream>
#include <set>
using namespace std;


set<pair<int,int> > cpus;
set<pair<int,int> > mems;
set<pair<int,int> > screens;
set<int> prices;

int main(){

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int cpu, mem, screen, price;
        cin >> cpu >> mem >> screen >> price;
        cpus.insert(pair<int,int>(cpu, price));
        mems.insert(pair<int,int>(mem, price));
        screens.insert(pair<int,int>(screen, price));
    }
    for(int i = 0; i < m; i++){
        int choice, min_spec;
        cin >> choice >> min_spec;
        set<pair<int,int> >::iterator it;
        set<int>::iterator it2;
        if(choice == 1){
            it = cpus.lower_bound(pair<int,int>(min_spec,0));
            it2 = prices.find(it->second);
            if(it != cpus.end()){
                for(it; it != cpus.end();it++){
                    it2 = prices.lower_bound(it->second);
                    if(it2 == prices.end()){
                        cout << it -> second <<endl;
                        break;
                    }
                }
                if(it != cpus.end()){
                    prices.insert(it->second);
                    cpus.erase(it);
                }
                else cout << 0 << endl;
            }else{
                cout << 0 << endl;
            }
        }else if(choice == 2){
            it = mems.lower_bound(pair<int,int>(min_spec,0));
            it2 = prices.find(it->second);
            if(it != mems.end()){
                for(it; it != mems.end();it++){
                    it2 = prices.lower_bound(it->second);
                    if(it2 == prices.end()){
                        cout << it -> second <<endl;
                        break;
                    }
                }
                if(it != mems.end()){
                    prices.insert(it->second);
                    mems.erase(it);
                }
                else cout << 0 << endl;
            }else{
                cout << 0 << endl;
            }
        }else if(choice == 3){
            it = screens.lower_bound(pair<int,int>(min_spec,0));
            it2 = prices.find(it->second);
            if(it != screens.end()){
                for(it; it != cpus.end();it++){
                    it2 = prices.lower_bound(it->second);
                    if(it2 == prices.end()){
                        cout << it -> second <<endl;
                        break;
                    }
                }
                if(it != screens.end()){
                    prices.insert(it->second);
                    screens.erase(it);
                }
                else cout << 0 << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }
}
