#include <bits/stdc++.h>

using namespace std;

int w[110], v[110] , dp[110][10100];

int main(){
    int n,m;
    scanf("%d %d", &n ,&m);
    for(int i = 1  ; i <= n ; i++){
        scanf("%d %d", &v[i] , &w[i]);
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
            if(j - w[i] < 0){
                continue;
            }
            dp[i][j] = max(dp[i][j] , dp[i-1][j-w[i]] + v[i]);
        }
    }
    printf("%d\n", dp[n][m]);

    return 0;

}

/*
4 8
15 1
10 5
9 3
5 4
*/
