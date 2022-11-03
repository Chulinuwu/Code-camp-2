#include <bits/stdc++.h>

using namespace std;

long long a[100100];

int main(){

    long long n , q , i , num;

    scanf("%lld %lld" , &n , &q);

    for(i = 1 ; i <= n ; i++){

        scanf("%lld" , &num);
        a[i] = a[i-1] + num;

    }

    for(i= n -1; i >= 1 ; i--){
        a[i] = min(a[i],a[i+1]);
    }

    while(q--){
        scanf("%lld" , &num);
        printf("%lld\n" , upper_bound(a+1, a+n+1 , num)- a-1);
    }


 return 0;
}

/*
5 3
10 20 -10 30 60
31
52
9
*/
