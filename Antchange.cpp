#include <bits/stdc++.h>

using namespace std;

char a[1100], b[1100];

int dp[1100][1100];

int main(){

    int q, lenA,lenB;

    scanf("%d", &q);

    while(q--){
        scanf(" %s %s", a+1 , b+1);

        lenA = strlen(a+1),lenB = strlen(b+1);

        for(int i = 1 ; i <= lenB ; i++){
            dp[0][i] = i;
        }
        for(int i = 1 ; i<= lenA ;  i++){
            dp[i][0] = i;
        }
        for(int i = 1 ; i <= lenA ; i++){
            for(int j = 1 ; j <= lenB ; j++){
                if(a[i] == b[j]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j] , min(dp[i-1][j-1],dp[i][j-1]))+1;
                }
            }
        }
        printf("%d\n", dp[lenA][lenB]);
        memset(dp,0,sizeof dp);
    }
    return 0;
}
