#include <bits/stdc++.h>

using namespace std;

int l[100100],r[100100],a[100100];

int main(){

    int q,n,sum,ans,Ma;

    scanf("%d" , &q);

    while(q--){

        scanf("%d", &n);

        for(int i = 1 ; i <= n ; i++){
            scanf("%d", &a[i]);
        }
        Ma = ans =-1e9;

        for(int i = 1 ,sum = 0; i <= n ; i++){
            sum += a[i];
            sum = max(sum,0), Ma = max(sum,Ma);
            l[i] = Ma;
        }
        Ma = ans = -1e9;

        for(int i = n , sum = 0 ; i >= 1 ; i--){
            sum += a[i];
            sum = max(sum,0),Ma = max(sum , Ma);
            r[i] = Ma;
        }
        for(int i = 1 ; i <= n ; i++){
            ans = max(ans,l[i]+r[i+1]);
        }
        printf("%d\n", ans);
    }


return 0;
}

/*
1
5
4
-6
3
-2
6
*/
