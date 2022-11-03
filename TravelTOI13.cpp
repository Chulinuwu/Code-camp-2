#include <bits/stdc++.h>

using namespace std;

struct A{
    int v,w;
    bool operator < (const A&o) const{
        return w > o.w;
    }
};

A now;
priority_queue <A> pq;
vector <A> g[10100];
int dis[10100],disR[10100];

int main(){
    int n , m ,u , v, w , st ,en, limit;

    scanf("%d %d %d %d %d" , &n , &m ,&st , &en , &limit );

    while(m--){
        scanf("%d %d %d", &u , &v ,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    for(int i = 0 ; i < n ; i++){
        dis[i] = 1e9;
    }
    dis[st] = 0;
    pq.push({st,0});

    while(!pq.empty()){
        now = pq.top();
        pq.pop();
        for(auto x : g[now.v]){
            if(now.w + x.w < dis[x.v]){
                dis[x.v] = now.w + x.w;
                pq.push({x.v,dis[x.v]});
            }
        }
    }

    int res = dis[en];

    if(dis[en] <= limit){
        printf("%d %d 0\n" , en , dis[en]);
        return 0;
    }

    int minn = 1e9 , pos = en;
    for(int i =0 ; i <n ;i++){
        disR[i]= 1e9;
    }
    disR[en] = 0;
    pq.push({en,0});

    while(!pq.empty()){
        now = pq.top();
        pq.pop();
        for(auto x : g[now.v]){
            if(now.w + x.w < disR[x.v]){
                disR[x.v] = now.w + x.w;
                pq.push({x.v,disR[x.v]});
                if(disR[x.v] <= minn && dis[x.v] <= limit){
                    if(disR[x.v]  == minn){
                        pos = min(pos,x.v);
                    }
                    else{
                        pos = x.v;
                    }
                    minn = min(minn , disR[x.v]);
                }
            }
        }
    }
    printf("%d %d %d\n", pos , dis[pos] , minn);

    return 0;
}

/*
8 11
0 5 200
0 1 10
0 2 10
1 3 10
1 5 70
2 3 10
2 4 30
2 6 10
3 5 30
4 5 20
6 7 15
7 5 20
*/