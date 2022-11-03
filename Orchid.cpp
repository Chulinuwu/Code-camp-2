#include <bits/stdc++.h>

using namespace std;

int a[1000010],dp[1000010];

int main(){

    int n, maxx = 0;
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n ; i++){
        int idx = upper_bound(dp,dp+maxx,a[i])-dp;
        if(idx == maxx){
            maxx++;
        }
        dp[idx] = a[i];
    }

    printf("%d\n", n - maxx);

    return 0;
}
