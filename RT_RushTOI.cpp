#include <bits/stdc++.h>
using namespace std;

#define INF 200000000
int g[510][510];

int main(){

    int n, m, i ,j ,k ,s , e ,w;

    scanf("%d %d", &n , &m);

    for(i = 1; i <= n ; i++ ){
        for(j = 1 ; j<= n ; j++){
            g[i][j] = INF;
        }
    }
    while(m--){
        scanf("%d %d %d" ,&s ,&e ,&w);
        if(w < g[s][e]){
            g[s][e] = w;
        }
    }
    for(k = 1 ; k <= n ; k++){
        for(i = 1 ; i<= n ; i++){
            for(j = 1 ; j <= n ; j++){
                g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
            }
        }
    }
    for(i = 1 ; i<= n ; i++){
        for(j=1 ; j< n ;j++){
            printf((g[i][j]== INF)?"0 " : "%d " ,g[i][j]);
        }
        printf((g[i][j] == INF)?"0\n":"%d\n",g[i][j]);
    }

    return 0;
}

/*
4 5
1 2 10
2 3 10
1 3 15
4 4 10
4 1 10
*/