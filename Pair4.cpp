#include <bits/stdc++.h>

using namespace std;
char a[10010]; int dp[1010][1010];

int play(int l , int r){
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    if(l >= r){
        return dp[l][r] = 0;
    }
    int maxx = -1e9;
    for(int i = l ; i < r ; i++){
        int value = play(l,i) + play(i+1,r);

        if(value > maxx){
            maxx = value;
        }
    }
    if(a[l] == a[r]){
        int value = play(l+1,r-1)+1;
        if(value > maxx){
            maxx = value;
        }
    }

    return dp[l][r] = maxx;
}

int main(){

    int n;
    memset(dp,-1,sizeof dp);
    scanf("%d",&n);
    for(int i = 1; i <= n ; i++){
        scanf(" %c", &a[i]);
    }
    play(1,n);
    printf("%d\n",dp[1][n]);

    return 0;

}

/*
6
U B N B O U

12
U B O U B O U B O U B O
*/
