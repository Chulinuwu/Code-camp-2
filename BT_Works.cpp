#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int dp[1010][1010];

int main(){

    int q,n,m,d,i,j,ans;

    scanf("%d" , &q);

    dp[0][0] =1;

    for(i = 1 ; i <= 1000 ; i++){
        dp[i][0] = 1;
        for(j = 1 ; j <= i ; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            dp[i][j] %= mod;
        }
    }

    while(q--){
        scanf("%d%d%d", &n ,&m , &d);

        if(d*(m-1) + m > n){
            ans = 0;
        }
        else{
            ans = dp[n-(d*(m-1))][m];
        }
        printf("%d\n", ans);
    }

    return 0;
}

/*
2
5 2 1
5 2 2
*/
