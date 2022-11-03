#include <bits/stdc++.h>

using namespace std;

int a[5101] = {1};

int main(){

    int i,j,n,k;

    scanf("%d %d", &n , &k);

    for(i = 1 ; i <= n ; i++){
        for(j = n ; j>= i ; j--){
            a[j] += a[j-i];
            a[j] %= k;
        }
    }

    printf("%d\n",a[n]-1);

    return 0;
}
