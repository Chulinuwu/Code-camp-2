#include <bits/stdc++.h>

using namespace std;

struct A{
    int s,e,w;
    bool operator < (const A&o) const{
        if(e != o.e){
            return e < o.e;
        }
        else if(s != o.s){
            return s < o.s;
        }
    }
}; A a[100100];

int dp[100100],b[100100];

int main(){

    int n;
    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d %d %d",&a[i].s, &a[i].e , &a[i].w);
    }
    sort(a+1,a+1+n);
    for(int i = 1 ; i <= n ; i++){
        b[i] = a[i].e;
    }
    for(int i = 1 ; i <= n ; i++){
        int ind = lower_bound(b+1, b+1+n,a[i].s)-b-1;
        dp[i] = max(dp[i-1],dp[ind]+a[i].w);
    }

    printf("%d\n",dp[n]);

    return 0;
}
