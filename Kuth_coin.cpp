#include <bits/stdc++.h>

using namespace std;

const int Max = 100000;

int coins[] = {1,5,10,25,50};

vector <long long> dp(Max,0);

int main(){

    int i,j,from,n,q;
    dp[0] = 1;

    for(i = 0 ; i < 5 ; i++){
        for(from = 0 , j = coins[i] ; j <= Max ; from++ , j++){
            dp[j] += dp[from]%1000003 , dp[j] %= 1000003;
        }
    }

    scanf("%d" , &q);

    while(q--){
        scanf("%d", &n);
        printf("%lld\n",dp[n]%1000003);
    }

    return 0;
}
