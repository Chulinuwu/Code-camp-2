#include <bits/stdc++.h>
#define max 2146483231
using namespace std;

int n,color[105][105],dp[105][105];

int main(){
    int i , k , j , l , temp , q, min;

    scanf("%d", &q);

    while(q--){
        scanf("%d" , &n);

        for(i = 0 ; i < n ; i++){
            scanf("%d", &color[i][i]);
        }
        for(l=2 ; l <= n ; l++){
            for(i = 0 ; i < n-l+1 ; i++){
                j = i+l-1 , min = max;
                for(k = i ; k <= j -1 ; k++){
                    temp = dp[i][k] + dp[k+1][j] + color[i][k] * color[k+1][j];
                    if(temp < min){
                        color[i][j] = (color[i][k] + color[k+1][j]) % 100;
                        min = temp , dp[i][j] = min;
                    }
                }
            }
        }
        printf("%d\n", dp[0][n-1]);
    }

    return 0;
}

