#include <bits/stdc++.h>

using namespace std;

struct A{
    int u , v , w;
};

A edge[1110];
int dis[1100],dis2[1100];
int main(){
    int n , m , k ,q ,now;
    scanf("%d %d %d %d",&n , &m , &k , &q);

    for(int i = 1 ; i <= m ; i++){
        scanf("%d %d %d", &edge[i].u , &edge[i].v , &edge[i].w);
    }
    for(int i = 1 ; i<= k ; i++){
        scanf("%d %d %d",&edge[i+m].u, &edge[i+m].v , &edge[i+m].w);
        edge[i+m].w *= -1;
    }
    while(q--){
        scanf("%d", &now); 
        for(int i = 1; i <= n ; i++){
            dis[i] = 1e9;
        }
        dis[now] = 0;
        for(int i = 1; i <= n-1 ; i++){
            for(int j = 1 ; j <= m+k ; j++){
                if(dis[edge[j].u] == 1e9){
                    continue;
                }
                if(dis[edge[j].u] + edge[j].w < dis[edge[j].v]){
                    dis[edge[j].v] = dis[edge[j].u] + edge[j].w;
                }
            }
        }
        for(int i =1 ; i <= n ; i++){
            dis2[i] = dis[i];
        }
        for(int j = 1 ; j <= m+k ; j++){
            if(dis[edge[j].u] == 1e9){
                continue;
            }
            if(dis[edge[j].u] + edge[j].w < dis[edge[j].v]){
                dis[edge[j].v] = dis[edge[j].u] + edge[j].w;
            }
        }

        for(int i = 1; i<= n ; i++){
            if(dis[i] != dis2[i] || (dis[i] == 1e9)){
                printf("-1 ");
            }
            else{
                printf("%d ", dis[i]);
            }
        }
        printf("\n");
    }
}


/*
10 5 5 5
1 7 8
2 5 1
3 4 7
5 8 4
5 1 11
10 1 6
10 5 3
10 3 1
9 5 10
5 7 2
2
4
6
8
10
*/