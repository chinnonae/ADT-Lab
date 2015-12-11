#include <iostream>
#include <vector>
#include <queue>
using namespace std;


#define MAX_N  100000

int n, r;
vector<int> adj[MAX_N];
int deg[MAX_N];
pair<int,int> nodes[MAX_N];
bool visited[MAX_N];

void init(){
    for(int i = 0 ; i < n; i++){
        deg[i] = 0;
        visited[i] = false;
    }
}

int read_input(){
    cin >> n >> r;
    nodes[0] = pair<int, int> (0, 0);
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        nodes[i] = pair<int, int>(x, y);
    }
    nodes[n+1] = pair<int, int>(100, 100);
    for(int i = 0 ; i <= n+1; i++)
        cout << "__" << nodes[i].first << ", " << nodes[i].second << endl;
}

int dist(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void create_path(){
    for(int i = 0 ; i < n+1; i++){
        for(int j = i+1; j <= n+1; j++){
            int dst = dist(nodes[i].first, nodes[i].second, nodes[j].first, nodes[j].second);
            if(dst <= r*r){
                adj[i].push_back(j);
                adj[j].push_back(i);
                deg[i]++;
                deg[j]++;
            }
        }
    }
}

void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        vector<int> vec = adj[t];
        for(int i = 0; i < deg[t]; i++){
            int u = vec[i];
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
            }
        }
    }

}

int main(){
    read_input();
    create_path();
    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j < deg[i]; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    bfs(0);

}



