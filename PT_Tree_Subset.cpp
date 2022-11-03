#include <bits/stdc++.h>

using namespace std;

vector<long long> g[100100];
long long v[100100],dp[100100][2],mark[100100];
void dfs(long long now){
    mark[now] = 1;
    dp[now][1] = v[now];
    for(auto x : g[now]){
        if(mark[x]){
            continue;
        }
        dfs(x);
        dp[now][0] += max(dp[x][0],dp[x][1]);
        dp[now][1] += dp[x][0];
    }
}

int main(){
    long long n , st , en ,Q , i;

    scanf("%lld", &Q);
    while(Q--){
        scanf("%lld", &n);
        for(i = 1; i <= n ; i++){
            scanf("%lld", &v[i]);
        }
        for(i= 1 ; i < n ; i++){
            scanf("%lld %lld" , &st , &en);
            g[st].push_back(en);
            g[en].push_back(st);
        }
        dfs(1);
        printf("%lld\n", max(dp[1][0],dp[1][1]));
        memset(v,0,sizeof v);
        memset(dp,0,sizeof dp);
        memset(mark,0,sizeof mark);
        for(i = 1 ; i<= n ; i++){
            g[i].clear();
        }
    }

    return 0;
}
/*
2
3
3 4 3
1 2
2 3
5 
3 2 10 10 10
1 2
2 3
1 5
4 2
*/