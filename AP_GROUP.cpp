#include <bits/stdc++.h>

using namespace std;

long long dp[100100];
pair<long long,long long> a[100100];

int main(){

    long long q,n;
    scanf("%lld", &q);
    while(q--){
        scanf("%lld" , &n);
        for(long long i = 1 ; i <= n ; i++){
            scanf("%lld %lld", &a[i].first, &a[i].second),a[i].second *= -1;
        }
        sort(a+1,a+1+n);
        long long maxx = 0 , idx;
        for(long long i = 1 ; i <= n ; i++){
            idx = upper_bound(dp,dp+maxx,a[i].second)-dp;
            if(maxx == idx){
                maxx++;
            }
            dp[idx] = a[i].second;
        }
        printf("%lld\n", maxx);
        memset(dp,0,sizeof dp);
    }
    return 0;
}
