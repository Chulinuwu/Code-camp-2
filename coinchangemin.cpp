#include <bits/stdc++.h>

using namespace std;

int dp[1000010],coin[15];

int main(){

    int n,m;
    scanf("%d %d", &n , &m);

    for(int i = 1 ; i<= n ; i++){
        scanf("%d", &coin[i]);
    }
    for(int i = 1 ; i <= m ; i++){
        dp[i] = 1e9;
        for(int j = 1; j <= n ; j++){
            if(i - coin[j] < 0){
                continue;
            }
            dp[i] = min(dp[i] , dp[i - coin[j]] + 1);
        }
    }
    if(dp[m] == 1e9){
        printf("0\n");
    }
    else{
        printf("%d\n",dp[m]);
    }

    return 0;
}
