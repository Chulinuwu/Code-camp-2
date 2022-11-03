#include <bits/stdc++.h>

using namespace std;

struct A{

    int v , w;
    bool operator < (const A&o) const{
        return w > o.w;
    }
};

A now;
int id[21000],dis[110][21000];
priority_queue<A>pq;
vector<A> g[21000];
vector<int> node[21000];

int main(){

    int q,n,m,a,u,v,w;

    scanf("%d", &q);

    while(q--){
        scanf("%d %d %d" , &n , &m , &a);
        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &id[i]);
            node[id[i]].push_back(i);
        }
        while(m--){
            scanf("%d %d %d", &u , &v , &w);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        for(int i = 1 ; i<= 100 ; i++){
            for(int j = 1 ; j <= n ; j++){
                dis[i][j] = 1e9;
            }
            for(auto x : node[i]){
                pq.push({x,0}),dis[i][x] = 0;
            }
            while(!pq.empty()){
                now = pq.top();
                pq.pop();
                for(auto x : g[now.v]){
                    if(now.w + x.w < dis[i][x.v]){
                        dis[i][x.v] = now.w + x.w;
                        pq.push({x.v,dis[i][x.v]});
                    }
                }
            }
        }
        int minn = 1e9;
        int sum = 0;
        vector <int> keep;
        for(int i = 1; i <= n ; i++){
            sum = 0;
            for(int j = 1 ; j <= 100 ; j++){
                if(dis[j][i] == 1e9){
                    continue;
                }
                keep.push_back(dis[j][i]);
            }
            sort(keep.begin(),keep.end());
            if(keep.size() < a){
                keep.clear();
                continue;
            }
            for(int k = 0 ; k < a ; k++){
                sum += keep[k];
            }
            minn = min(minn,sum);
            keep.clear();
        }
        printf("%d\n",minn);

        keep.clear();

        for(int i = 1; i <= n ; i++){
            g[i].clear();
        }
        for(int i = 1 ; i<= 100 ; i++){
            node[i].clear();
        }
    }

    return 0;
}

/*
2
3 2 2
1 2 3
1 2 1
2 3 3
5 5 3
1 3 4 2 3
1 2 5
2 3 2
3 4 5
4 1 3
4 5 2
*/