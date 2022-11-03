#include <bits/stdc++.h>

using namespace std;

long long a[500100],st[500100],dp[500100];

int main(){

    long long n , i , sum = 0;
    scanf("%lld" , &n);

    for(i = 1 ; i <= n ; i++){
        scanf("%lld", &a[i]);
    }
    for(i = 1 ; i <= n ; i++){
        scanf("%lld", &st[i]);
    }

    sort(a+1,a+1+n);

    sort(st+1,st+1+n,greater<int>());

    for(i = 1 ; i<= n ; i++){
        dp[i] = a[i] + st[i];
    }

    sort(dp+1 , dp+1+n);

    for(i = 2 ; i <= n ; i++){
        sum += abs(dp[i]-dp[i-1]);
    }

    printf("%lld", sum);

    return 0;

}

/*
3
158 168 139
132 104 140
18

2
11 28
68 38
13

3
9 1 7
6 4 4
6
*/
