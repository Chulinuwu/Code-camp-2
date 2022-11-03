#include <bits/stdc++.h>

using namespace std;

struct A{

    int v , w,fuel , use ,ch;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};

struct B{
    int v,w;
};

A now;
vector <B> g[105];
priority_queue<A> heap;
int cost[105],dis[105][105];

int main(){

    int n, st ,en ,full,m , u ,v ,w;
    scanf("%d", &n);

    for(int i = 1;  i <= n ; i++){
        scanf("%d" ,&cost[i]);
    }
    scanf("%d %d %d %d" , &st, &en , &full , &m);
    for(int i = 1 ; i<= m ; i++){
        scanf("%d %d %d", &u , &v ,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int minn = 1e9;
    for(int k = 1; k <= n ; k++){
        for(int i = 1 ; i<= n ; i++){
            for(int j = 0 ; j <= full ; j++){
                dis[i][j] = 1e9;
            }
        }
    
    dis[st][0] = 0;
    heap.push({st,0,0,k,1});

    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == en && now.fuel == full){
            minn = min(minn , dis[en][full]);
            break;
        }
        if(now.ch && now.use == now.v && now.w < dis[now.v][full]){
            dis[now.v][full] = now.w;
            heap.push({now.v,dis[now.v][full] , full , now.use,0});
        }
        if(now.fuel + 1 <= full && now.w + cost[now.v] < dis[now.v][now.fuel+1]){
            dis[now.v][now.fuel+1] = now.w +cost[now.v];
            heap.push({now.v,dis[now.v][now.fuel+1],now.fuel+1,now.use,now.ch});
        }
        for(int i = 0 ; i < (int)g[now.v].size() ; i++){
            if(now.fuel - g[now.v][i].w >= 0 && now.w < dis[g[now.v][i].v][now.fuel-g[now.v][i].w]){
                dis[g[now.v][i].v][now.fuel-g[now.v][i].w] = now.w;
                heap.push({g[now.v][i].v,now.w,now.fuel-g[now.v][i].w,now.use,now.ch});
            }
        }
    }
}
    printf("%d\n",minn);
    return 0;
}

/*
4
7 1 8 10
1 4 100
5
1 2 60
1 3 50
1 4 90
2 4 30
3 4 20
*/