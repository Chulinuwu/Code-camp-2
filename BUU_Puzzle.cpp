#include <bits/stdc++.h>

using namespace std;

int a[10][50100] ,s[13] = {0,1,2,4,5,8,9,10,16,17,18,20,21};
int dp[25][50100];

int main(){

    int q,m;
    scanf("%d",&q);

    while(q--){
        int ans = 0;
        scanf("%d", &m);
        for(int i = 0 ; i < 5 ; i++){
            for(int j = 0 ; j< m ; j++){
                scanf("%d", &a[i][j]);
            }
        }
        for(int j = 0 ; j < m ;j++){
            for(int k = 0 ; k<13 ; k++){
                int sum = 0 ;
                for(int i= 0 ; i < 5 ;i++){
                    if(s[k]&(1<<i)){
                        sum += a[i][j];
                    }
                }
                if(j== 0){
                    dp[k][j] = sum;
                }
                else{
                    for(int kk = 0 ; kk < 13 ; kk++){
                        if(s[k]&s[kk]){
                            continue;
                        }
                        dp[k][j] = max(dp[k][j],dp[kk][j-1] + sum);
                    }
                }
            }
        }
        for(int k = 0 ; k < 13 ; k++){
            ans = max(ans,dp[k][m-1]);
        }
        printf("%d\n",ans);
        memset(dp,0,sizeof dp);
    }
    return 0;
}

/*
2
6
1 0 0 0 0 0
*/