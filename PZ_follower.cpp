#include <bits/stdc++.h>

using namespace std;

int mark[1024][105];

struct A{

    int v,w;
};

queue <A> q;

vector <A> pa[105];

int main(){

    int n,m,s,e,c,b,d,v,w,i,t;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d %d %d" , &n ,&m , &s , &e);
        while(m--){
            scanf("%d %d %d" , &b , &c ,&d);
            pa[b].push_back({c,d});
            pa[c].push_back({b,d});
        }
        q.push({s,0});
        while(!q.empty()){
            v = q.front().v;
            w = q.front().w;
            q.pop();
            if(mark[w][v] != 0){
                continue;
            }
            mark[w][v] = 1;
            for(i = 0 ; i < pa[v].size() ; i++){
                q.push({pa[v][i].v, w^pa[v][i].w});
            }
        }
        for(i = 0 ; i < 1024 ; i++){
            if(mark[i][e] != 0){
                printf("%d\n" , i);
                break;
            }
        }
        for(i = 1 ; i <= n ; i++){
            pa[i].clear();
        }
        memset(mark,0,sizeof(mark));
    }

    return 0;

}

/*
1
4 4 1 4
1 2 3
1 3 5
2 3 1
3 4 4
*/
