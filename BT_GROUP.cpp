#include <bits/stdc++.h>

using namespace std;

priority_queue<long long , vector <long long>, greater<long long>> pq;

int main(){

    int q;

    scanf("%d", &q);

    while(q--){
        while(!pq.empty()){
            pq.pop();
        }
        int n,k;
        scanf("%d %d", &n ,&k);
        long long last,val;
        scanf("%lld", &last);
        for(int i = 2 ; i <= n ; i++){
            long long val;
            scanf("%lld", &val);
            pq.emplace(val-last);
            last = val;
        }

        long long ans = 0;

        while(pq.size() >= k){
            ans += pq.top();
            pq.pop();
        }

        printf("%lld\n",  ans);
    }


    return 0;
}

/*
1
9 3
2 2 4 5 6 8 10 11 17
*/
