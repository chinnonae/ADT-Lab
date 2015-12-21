#include <iostream>
#include <queue>
using namespace std;

bool ans(int c, int d, int h, vector<pair<int, int> > nodes[],int n){
    if(c == d)return true;
    bool passed[n];
    vector<pair<int,int> > vec;
    queue<int> q;
    q.push(c);
    while(!q.empty()){
        int z = q.front();
        q.pop();
        passed[z] = true;
        vec = nodes[z];
        for(int i = 0; i < vec.size(); i++){
            if(vec[i].second >= h){
                if(vec[i].first == d) return true;
                if(!passed[vec[i].first])q.push(vec[i].first);
                passed[vec[i].first] = true;
            }
        }
    }
    return false;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int> > nodes[n+1];
    for(int i = 0; i < m; i++){
        int c, d, h;
        cin >> c >> d >> h;
        nodes[c].push_back(pair<int,int>(d,h));
        nodes[d].push_back(pair<int,int>(c,h));
    }
    for(int i = 0; i < k; i++){
        int c, d, h;
        cin >> c >> d >> h;
        if(ans(c,d,h,nodes,n)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}
