#include <bits/stdc++.h>

using namespace std;

long long val[100010],sum,nin;

vector <int> adj[100010];

void dfs(int u , int p){
    for(auto x : adj[u]){
        if(x == p){
            continue;
        }
        dfs(x,u);
        val[u] += val[x];
    }
    nin = min(nin , abs(sum - 2 * val[u]));
}

void solve(){
    int n,u,v;

    cin >> n;

    for(int i = 1 ; i < n ; ++i){
        cin >> u >> v;
        adj[u].push_back(v),adj[v].push_back(u);
    }

    sum = 0 , nin = LLONG_MAX;

    for(int i = 1 ; i<= n ; ++i){
        cin >> val[i];
        sum += val[i];
    }
    dfs(1,0);

    cout << nin;

    for(int i = 1 ; i <= n ; ++i){
        adj[i].clear();
    }
    return;
}

int main(){

    cin.tie(0) -> sync_with_stdio(0);

    int q;

    cin >> q;

    while(q--){
        solve();
        cout << endl;
    }

    return 0;

}

/*
2
6
1 2
1 3
1 5
5 6
6 4
2 1 3 3 4 6
3
1 2
1 3
10 4 3
*/
