#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PI;

priority_queue<PI> h;

int dp[500100];

int main(){

        int n, k , i , num;

        scanf("%d %d %d", &n , &k ,&i);

        dp[1] = i;

        h.push({-i,1});

        for(int i = 2 ; i <= n ; i++){
            scanf("%d" , &num);

            while(!h.empty() && i-h.top().second > k){
                h.pop();
            }
            dp[i] = -(h.top().first) + num;
            h.push({-dp[i],i});
        }

        printf("%d\n", dp[n]);

        return 0;
}
