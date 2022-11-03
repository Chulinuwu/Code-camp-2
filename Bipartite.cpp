#include <bits/stdc++.h>

using namespace std;

vector <int> g[100100];
int color[100100];

int check(int v, int col){
    if(color[v] != 0){
        return (color[v] == col);
    }
    color[v] = col;
    for(auto x: g[v]){
        if(!check(x,3-col)){
            return 0;
        }
    }
    return 1;
}

int main(){

    int q,n,m,i,u,v;

    scanf("%d" , &q);

    while(q--){
        int ch = 1;
        scanf("%d %d", &n ,&m);

        while(m--){
        scanf("%d %d" , &u , &v);
        g[u].push_back(v);
        g[v].push_back(u);
        }
        for(i = 1 ; i <= n ; i++){
            if(color[i] == 0){
                if(!check(i,1)){
                    ch = 0;
                    break;
                }
            }
        }
        if(ch){
            printf("yes\n");
        }
        else{
        printf("no\n");
        }
        memset(color,0,sizeof color);
        for(int i = 1 ; i<= n ; i++){
            g[i].clear();
        }
    }
    return 0;
}
