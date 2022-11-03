#include <bits/stdc++.h>

using namespace std;

int l[100002];
int r[100002];
int n,q,i;
long long a[100002];

int main(){

scanf("%d", &q);

while(q--){

    scanf("%d" , &n);

    long long mx = 0;

    for(i = 1; i <= n ; i++){
        scanf("%lld", &a[i]);
    }
    for(i = 1 ; i <= n ; i++){
        l[i] = i-1;
        while(l[i] > 0 && a[i] <= a[l[i]]){
            l[i] = l[l[i]];
        }
    }
    for(int i = n ; i > 0 ; i--){
        r[i] = i+1;
        while(r[i] <= n && a[i] <= a[r[i]]){
            r[i] = r[r[i]];
        }
    }
    for(i = 1 ; i<= n ; i++){
        mx = max(mx,a[i]*(r[i]- l[i] - 1));
    }
        printf("%lld\n", mx);

}

return 0;

}

/*
2
6
2 1 5 6 2 38
3
100 100 100
*/
