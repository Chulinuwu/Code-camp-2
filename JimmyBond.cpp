#include <bits/stdc++.h>

using namespace std;

double a[25][25],dp[22][1<<22];
int n;;
double play(int state , int mask){
    if(state == n){
        return 1;
    }
    if(dp[state][mask] != -1){
        return dp[state][mask];
    }
    for(int i = 0 ; i< n ; i++){
        if(mask & (1 << i)){
            continue;
        }
        dp[state][mask] = max(dp[state][mask] , play(state +1 , mask | (1 << i)) * a[i][state]); 
    }
    return dp[state][mask];
}

int main(){
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%lf", &a[i][j]);
            a[i][j] /=   100;
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < (1<<n) ; j++){
            dp[i][j] = -1;
        }
    }
    printf("%.2lf", play(0,0)*100);

    return 0;
}