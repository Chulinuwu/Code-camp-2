#include <bits/stdc++.h>

using namespace std;

int main(){

    long long q,s,m;

    scanf("%lld", &q);

    while(q--){
    scanf("%lld %lld", &s , &m);

    long long l = 0 , r = s/2 , ch =1;

    while(l <= r){
        long long mid = (l+r)/2;
        long long b = s-mid;

        if(mid*b> m || mid *b/b != mid){
            r = mid - 1;
        }
        else if(mid*b < m){
            l = mid +1;
        }
        else{
            printf("%lld %lld\n", mid , b);
            ch = 0;
            break;
        }
    }
    if(ch){
        printf("No answer\n");
    }
    }

    return 0;
}
/*

3
8 16
2022 1022117
10 20
*/
