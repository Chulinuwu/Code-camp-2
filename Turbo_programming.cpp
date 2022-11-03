#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin() , (x).end()

struct Node{

    int u , w;
    bool operator < (const Node & o) const{
        return w > o.w;
    }

};

vector <pair<int,int>> adj[100100];

int dist[100100];
bool visited[100100];

int main(){

    cin.tie(0) ->sync_with_stdio(0);
    int n, q , m , u , v, w, x;

    cin >> n >> m >> q;

    for(int i = 1 ; i<= m  ;i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v,w);
    }
    memset(dist,-1,sizeof dist);

    priority_queue <Node> pq;

    pq.push({1,0});

    dist[1] = 0;

    while(!pq.empty()){
        Node now = pq.top();

        pq.pop();

        if(visited[now.u]){
            continue;
        }
        visited[now.u] = true;
        dist[now.u] = now.w;
        for(auto x : adj[now.u]){
            pq.push({x.first , now.w + x.second});
        }
    }

    while(q--){
        cin >> x;
        cout << dist[x] << endl;
    }

    return 0;
    
}

/*
6 5 3
1 2 10
2 3 10
3 4 10
4 5 10
1 5 50
6
*/