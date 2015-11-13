#include <iostream>
#include <queue>
using namespace std;

bool caches[1000001] = {false};

int main(){
    int n, m, misses = 0;
    cin >> n;
    cin >> m;

    queue<int> cache;

    for(m; m > 0 ; m--){
        int id;
        cin >> id;

        bool hit = caches[id];

        if(!hit){
            if(cache.size() >= n){
                int oldcache = cache.front();
                cache.pop();
                caches[oldcache] = false;
            }
            cache.push(id);
            misses += 1;
            caches[id] = true;
        }
    }
    cout << misses << endl;
}

